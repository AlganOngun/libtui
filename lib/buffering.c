#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "buf_errs.h"
#include "libtui.h"
#include "libtui_error.h"

buf* buf_create(size_t row, size_t column) {
  char* b = malloc(row * column);
  buf* buffer = malloc((row * column) + sizeof(size_t) * 2);

  buffer->buf = b;
  buffer->rows = row;
  buffer->columns = column;

  return buffer;
}

size_t buf_map_i(const buf* buf, size_t x, size_t y) {
  return buf->columns * y + x;
}

void buf_set_row(buf* buf, const char* row, size_t row_index) {
  if (row_index >= buf->rows) buff_errs_throw_invalid_row(buf, row_index);

  size_t row_len = strlen(row);
  if (row_len > buf->columns) buff_errs_throw_invalid_row_len(buf, row_len);

  for (size_t y = 0; y < buf->rows; ++y) {
    for (size_t x = 0; x < buf->columns; ++x) {
      buf_set(buf, row[x], x, y);
    }
  }
}

void buf_set(buf* buf, const char c, size_t x, size_t y) {
  if (x < 0) buff_errs_throw_negative_x(buf, x);

  if (y < 0) buff_errs_throw_negative_y(buf, y);
  if (x >= buf->columns) buff_errs_throw_invalid_x(buf, x);
  if (y >= buf->rows) buff_errs_throw_invalid_y(buf, y);

  const size_t i = buf_map_i(buf, x, y);
  buf->buf[i] = c;
}

char buf_get(const buf* buf, size_t x, size_t y) {
  if (x < 0) buff_errs_throw_negative_x(buf, x);

  if (y < 0) buff_errs_throw_negative_y(buf, y);
  if (x >= buf->columns) buff_errs_throw_invalid_x(buf, x);
  if (y >= buf->rows) buff_errs_throw_invalid_y(buf, y);

  const size_t i = buf_map_i(buf, x, y);
  return buf->buf[i];
}

void buf_free(buf* buf) {
  free(buf->buf);
  free(buf);
}
