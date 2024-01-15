#include "libtui_buffering.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libtui.h"
#include "libtui_error.h"

buf* buf_create(size_t column, size_t row) {
  buf* buffer = malloc(sizeof(buf));
  libtui_error_assert(
      buffer == NULL,
      libtui_error_create("Error buf_create: couldn't allocate buf* buffer. Malloc Failed!"));

  buffer->buf = malloc(row * (column + 1));
  libtui_error_assert(
      buffer->buf == NULL,
      libtui_error_create("Error buf_create: couldn't allocate char* buffer->buf. Malloc Failed!"));

  buffer->rows = row;
  buffer->columns = column + 1;

  for (size_t y = 0; y < row; ++y) {
    const size_t i = buf_map_i(buffer, column, y);
    buffer->buf[i] = '\n';
  }

  return buffer;
}

size_t buf_map_i(const buf* buf, size_t x, size_t y) {
  return buf->columns * y + x;
}

void buf_set(buf* buf, const char c, size_t x, size_t y) {
  const size_t i = buf_map_i(buf, x, y);
  buf->buf[i] = c;
}

char buf_get(const buf* buf, size_t x, size_t y) {
  const size_t i = buf_map_i(buf, x, y);
  return buf->buf[i];
}

void buf_free(buf* buf) {
  libtui_error_assert(
      buf == NULL,
      libtui_error_create(
          "Error buf_free: Can't free a null buf* buf, please try to free a valid buf"));
  free(buf->buf);
  free(buf);
}
