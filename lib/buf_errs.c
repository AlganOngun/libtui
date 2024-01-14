#include "buf_errs.h"

#include <stdio.h>
#include <stdlib.h>

#include "buffering.h"
#include "libtui_error.h"

void buff_errs_throw_invalid_row(const buf* buf, size_t row_index) {
  char* msg;
  sprintf(
      msg,
      "Error in buf_set_row: Can't set the row in buffer. row_index is invalid. |row_index %zu is bigger or equal to row count(buf->rows) of buf, %zu|\n",
      row_index,
      buf->rows);

  libtui_error_throw(libtui_error_create(msg));
}

void buff_errs_throw_invalid_row_len(const buf* buf, size_t row_len) {
  char* msg;
  sprintf(
      msg,
      "Error in buf_set_row: Can't set the row in buffer. input \"row\" is invalid. |strlen(row) %zu > buf->columns %zu|",
      row_len,
      buf->columns);

  libtui_error_throw(libtui_error_create(msg));
}

void buff_errs_throw_negative_x(const buf* buf, size_t x) {
  char* msg;
  sprintf(msg, "Error in buf_set: x %zu, is smaller than 0. x and y should be bigger than 0", x);

  libtui_error_throw(libtui_error_create(msg));
}

void buff_errs_throw_negative_y(const buf* buf, size_t y) {
  char* msg;
  sprintf(msg, "Error in buf_set: y %zu, is smaller than 0. x and y should be bigger than 0", y);

  libtui_error_throw(libtui_error_create(msg));
}

void buff_errs_throw_invalid_x(const buf* buf, size_t x) {
  char* msg;
  sprintf(msg,
          "Error in buf_set: x %zu, is invalid. x %zu must be smaller than buf->columns %zu",
          x,
          x,
          buf->columns);

  libtui_error_throw(libtui_error_create(msg));
}

void buff_errs_throw_invalid_y(const buf* buf, size_t y) {
  char* msg;
  sprintf(msg,
          "Error in buf_set: y %zu, is invalid. y %zu must be smaller than buf->rows %zu",
          y,
          y,
          buf->rows);

  libtui_error_throw(libtui_error_create(msg));
}
