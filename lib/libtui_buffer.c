#include "libtui_buffer.h"

#include <stdio.h>
#include <stdlib.h>

struct libtui_buffer *libtui_buffer_create(size_t column, size_t row)
{
	struct libtui_buffer *buffer = malloc(sizeof(*buffer));
	if (buffer == NULL)
		goto defer;

	buffer->buf = malloc(row * (column + 1));
	if (buffer->buf == NULL)
		goto defer;

	buffer->rows = row;
	buffer->columns = column + 1;

	for (size_t y = 0; y < row; ++y) {
		const size_t i = libtui_buffer_get_index(buffer, column, y);
		buffer->buf[i] = '\n';
	}

defer:
	if (buffer->buf)
		return buffer;
	return NULL;
}

size_t libtui_buffer_get_index(const struct libtui_buffer *const buf, size_t x,
			       size_t y)
{
	return buf->columns * y + x;
}

void libtui_buffer_set(struct libtui_buffer *const buf, const char c, size_t x,
		       size_t y)
{
	const size_t i = libtui_buffer_get_index(buf, x, y);
	buf->buf[i] = c;
}

char libtui_buffer_get(const struct libtui_buffer *const buf, size_t x,
		       size_t y)
{
	const size_t i = libtui_buffer_get_index(buf, x, y);

	return buf->buf[i];
}

void libtui_buffer_free(struct libtui_buffer *buf)

{
	free(buf->buf);
	free(buf);
}
