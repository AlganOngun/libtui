#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "buf_errs.h"
#include "libtui.h"
#include "libtui_error.h"

buf* buf_create(int row, int column) {
  char* b = malloc(row * column);
  buf* buffer = malloc((row * column) + sizeof(int) * 2);

  buffer->buf = b;
  buffer->rows = row;
  buffer->columns = column;

  return buffer;
}

void buf_set_row(buf* buf, const char* row, int row_index) {
  if (row_index >= buf->rows) buff_errs_throw_invalid_row(buf, row_index);

  int row_len = strlen(row);
  if (row_len > buf->columns) buff_errs_throw_invalid_row_len(buf, row_len);

  for (size_t y = 0; y < buf->rows; ++y) {
    for (size_t x = 0; x < buf->columns; ++x) {
      const int i = buf->columns * y + x;
      buf->buf[i] = row[x];
    }
  }
}

void buf_set(buf* buf, const char c, int x, int y) {
  if (x < 0) buff_errs_throw_negative_x(buf, x);

  if (y < 0) buff_errs_throw_negative_y(buf, y);
  if (x >= buf->columns) buff_errs_throw_invalid_x(buf, x);
  if (y >= buf->rows) buff_errs_throw_invalid_y(buf, y);

  const int i = buf->columns * y + x;
  buf->buf[i] = c;
}

void buf_free(buf* buf) {
  free(buf->buf);
  free(buf);
}
