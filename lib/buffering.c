#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libtui.h"

buf* buf_create(int row, int column) {
  char* b = malloc(row * column);
  buf* buffer = malloc((row * column) + sizeof(int) * 2);

  buffer->buf = b;
  buffer->rows = row;
  buffer->columns = column;

  return buffer;
}

void buf_set_row(buf* buf, const char* row, int row_index) {
  if (row_index > buf->rows) {
    fprintf(
        stderr,
        "Error in buf_set_row: Can't set the row in buffer. row_index is invalid. |row_index %d is bigger than row count(buf->rows) of buf, %d|",
        row_index,
        buf->rows);
    exit(EXIT_FAILURE);
  }

  int row_len = strlen(row);
  if (row_len > buf->columns) {
    fprintf(
        stderr,
        "Error in buf_set_row: Can't set the row in buffer. input \"row\" is invalid. |strlen(row) %d > buf->columns %d|",
        row_len,
        buf->columns);
    exit(EXIT_FAILURE);
  }

  for (size_t y = 0; y < buf->rows; ++y) {
    for (size_t x = 0; x < buf->columns; ++x) {
      const int i = buf->columns * y + x;
      buf->buf[i] = row[x];
    }
  }
}

void buf_set(buf* buf, const char c, int x, int y) {
  if (x < 0) {
    fprintf(
        stderr, "Error in buf_set: x %d, is smaller than 0. x and y should be bigger than 0", x);
    exit(EXIT_FAILURE);
  }
  if (y < 0) {
    fprintf(stderr, "Error in buf_set: y %d, is smaller than 0. x and y must be bigger than 0", x);
    exit(EXIT_FAILURE);
  }
  if (x >= buf->columns) {
    fprintf(stderr,
            "Error in buf_set: x %d, is invalid. x %d must be smaller than buf->columns %d",
            x,
            x,
            buf->columns);
    exit(EXIT_FAILURE);
  }
  if (y >= buf->rows) {
    fprintf(stderr,
            "Error in buf_set: y %d, is invalid. y %d must be smaller than buf->rows %d",
            y,
            y,
            buf->rows);
    exit(EXIT_FAILURE);
  }

  const int i = buf->columns * y + x;
  buf->buf[i] = c;
}

void buf_free(buf* buf) {
  free(buf->buf);
  free(buf);
}
