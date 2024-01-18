#include "libtui_buffer.h"

#include <stdio.h>
#include <stdlib.h>

const char *libtui_buffer_err_str(enum LIBTUI_BUFFER_ERR err)
{
	const char *LIBTUI_BUFFER_ERR_STR[] = {
		"BUFFER_ERROR_OK",
		"BUFFER_ERROR_INVALID_DIMENSION",
		"BUFFER_ERROR_MALLOC_FAILED",
		"BUFFER_ERROR_NULL_BUF",
		"BUFFER_ERROR_NULL_BUF_BUFFER",
	};

	const char *err_str = NULL;

	if (err >= BUFFER_ERROR_COUNT)
		err_str = NULL;

	err_str = LIBTUI_BUFFER_ERR_STR[err];
	return err_str;
}

struct libtui_buffer *libtui_buffer_create(size_t column, size_t row,
					   enum LIBTUI_BUFFER_ERR *result)
{
	struct libtui_buffer *buffer = malloc(sizeof(*buffer));
	if (buffer == NULL) {
		*result = BUFFER_ERROR_MALLOC_FAILED;
		goto fatal_error;
	}

	buffer->buf = malloc(row * (column + 1));
	if (buffer->buf == NULL) {
		*result = BUFFER_ERROR_MALLOC_FAILED;
		goto fatal_error;
	}

	buffer->rows = row;
	buffer->columns = column + 1;

	for (size_t y = 0; y < row; ++y) {
		enum LIBTUI_BUFFER_ERR buffer_get_index_result;
		const size_t i = libtui_buffer_get_index(
			buffer, column, y, &buffer_get_index_result);

		buffer->buf[i] = '\n';
	}

	*result = BUFFER_ERROR_OK;
	return buffer;

fatal_error:
	return NULL;
}

size_t libtui_buffer_get_index(const struct libtui_buffer *buf, size_t x,
			       size_t y, enum LIBTUI_BUFFER_ERR *result)
{
	if (buf == NULL) {
		*result = BUFFER_ERROR_NULL_BUF;
		goto error_return_0;
	}
	if (x > buf->columns || y >= buf->rows) {
		*result = BUFFER_ERROR_INVALID_DIMENSION;
		goto error_return_0;
	}

	*result = BUFFER_ERROR_OK;
	return buf->columns * y + x;

error_return_0:
	return 0;
}

void libtui_buffer_set(struct libtui_buffer *buf, const char c, size_t x,
		       size_t y, enum LIBTUI_BUFFER_ERR *result)
{
	if (buf == NULL) {
		*result = BUFFER_ERROR_NULL_BUF;
		goto error_return_early;
	}

	if (buf->buf == NULL) {
		*result = BUFFER_ERROR_NULL_BUF_BUFFER;
		goto error_return_early;
	}

	if (x > buf->columns || y >= buf->rows) {
		*result = BUFFER_ERROR_INVALID_DIMENSION;
		goto error_return_early;
	}

	// Didn't error check because any error is impossible
	enum LIBTUI_BUFFER_ERR buffer_get_index_result;
	const size_t i =
		libtui_buffer_get_index(buf, x, y, &buffer_get_index_result);

	*result = BUFFER_ERROR_OK;
	buf->buf[i] = c;

error_return_early:
	return;
}

char libtui_buffer_get(const struct libtui_buffer *buf, size_t x, size_t y,
		       enum LIBTUI_BUFFER_ERR *result)
{
	if (buf == NULL) {
		*result = BUFFER_ERROR_NULL_BUF;
		goto error_return_null_char;
	}
	if (buf->buf == NULL) {
		*result = BUFFER_ERROR_NULL_BUF_BUFFER;
		goto error_return_null_char;
	}
	if (x > buf->columns || y >= buf->rows) {
		*result = BUFFER_ERROR_INVALID_DIMENSION;
		goto error_return_null_char;
	}

	// Didn't error check because any error is impossible
	enum LIBTUI_BUFFER_ERR buffer_get_index_result;
	const size_t i =
		libtui_buffer_get_index(buf, x, y, &buffer_get_index_result);

	*result = BUFFER_ERROR_OK;
	return buf->buf[i];

error_return_null_char:
	return '\0';
}

void libtui_buffer_free(struct libtui_buffer *buf,
			enum LIBTUI_BUFFER_ERR *result)
{
	if (buf == NULL) {
		*result = BUFFER_ERROR_NULL_BUF;
		goto error_return_early;
	}

	if (buf->buf == NULL) {
		*result = BUFFER_ERROR_NULL_BUF_BUFFER;
		goto error_return_early;
	}

	*result = BUFFER_ERROR_OK;
	free(buf->buf);
	free(buf);

error_return_early:
	return;
}
