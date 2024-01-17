#include "libtui_buffering.h"

#include <stdio.h>
#include <stdlib.h>

#include "libtui_buffering_errs.h"

#define FAIL_WITH_ERR(label, result, err_code) \
	*(result) = (err_code);                \
	goto label;

struct libtui_buffer *buf_create(size_t column, size_t row,
				 enum LIBTUI_BUFFERING_ERR *result)
{
	struct libtui_buffer *buffer = malloc(sizeof(*buffer));
	if (buffer == NULL) {
		FAIL_WITH_ERR(fatal_error, result,
			      BUFFERING_ERROR_MALLOC_FAILED)
	}

	buffer->buf = malloc(row * (column + 1));
	if (buffer->buf == NULL) {
		FAIL_WITH_ERR(fatal_error, result,
			      BUFFERING_ERROR_MALLOC_FAILED)
	}

	buffer->rows = row;
	buffer->columns = column + 1;

	for (size_t y = 0; y < row; ++y) {
		enum LIBTUI_BUFFERING_ERR buffer_get_index_result;
		const size_t i = libtui_buffer_get_index(
			buffer, column, y, &buffer_get_index_result);
		if (buffer_get_index_result != BUFFERING_ERROR_OK) {
			// Print an error message to stderr and exit the program
		}

		buffer->buf[i] = '\n';
	}

	*result = BUFFERING_ERROR_OK;
	return buffer;

fatal_error:
	return NULL;
}

size_t libtui_buffer_get_index(const struct libtui_buffer *buf, size_t x,
			       size_t y, enum LIBTUI_BUFFERING_ERR *result)
{
	if (buf == NULL) {
		FAIL_WITH_ERR(fatal_error, result, BUFFERING_ERROR_NULL_BUF)
	}
	if (x >= buf->columns || y >= buf->rows) {
		FAIL_WITH_ERR(fatal_error, result,
			      BUFFERING_ERROR_INVALID_DIMENSION)
	}

	*result = BUFFERING_ERROR_OK;
	return buf->columns * y + x;

fatal_error:
	return 0;
}

enum LIBTUI_BUFFERING_ERR libtui_buffer_set(struct libtui_buffer *buf,
					    const char c, size_t x, size_t y)
{
	if (buf == NULL)
		return BUFFERING_ERROR_NULL_BUF;
	if (buf->buf == NULL)
		return BUFFERING_ERROR_NULL_BUF_BUFFER;

	enum LIBTUI_BUFFERING_ERR get_index_result;
	const size_t i = libtui_buffer_get_index(buf, x, y, &get_index_result);
	if (get_index_result != BUFFERING_ERROR_OK) {
		// Print an error message to stderr and exit the program
	}

	buf->buf[i] = c;
	return BUFFERING_ERROR_OK;
}

char libtui_buffer_get(const struct libtui_buffer *buf, size_t x, size_t y,
		       enum LIBTUI_BUFFERING_ERR *result)
{
	if (buf == NULL) {
		FAIL_WITH_ERR(fatal_error, result, BUFFERING_ERROR_NULL_BUF)
	}
	if (buf->buf == NULL) {
		FAIL_WITH_ERR(fatal_error, result,
			      BUFFERING_ERROR_NULL_BUF_BUFFER)
	}
	if (x >= buf->columns || y >= buf->rows) {
		FAIL_WITH_ERR(fatal_error, result,
			      BUFFERING_ERROR_INVALID_DIMENSION)
	}

	*result = BUFFERING_ERROR_OK;

	enum LIBTUI_BUFFERING_ERR get_index_result;
	const size_t i = libtui_buffer_get_index(buf, x, y, &get_index_result);
	if (get_index_result != BUFFERING_ERROR_OK) {
		// Print an error message to stderr and exit the program
	}

	return buf->buf[i];

fatal_error:
	return '\0';
}

enum LIBTUI_BUFFERING_ERR libtui_buffer_free(struct libtui_buffer *buf)
{
	if (buf == NULL)
		return BUFFERING_ERROR_NULL_BUF;

	if (buf->buf == NULL)
		return BUFFERING_ERROR_NULL_BUF_BUFFER;

	free(buf->buf);
	free(buf);
	return BUFFERING_ERROR_OK;
}
