#include "buf_errs.h"

#include <stdio.h>
#include <stdlib.h>

#include "buffering.h"
#include "libtui_error.h"

void buff_errs_throw_invalid_row(buf* buf, int row_index) {
  char* msg;
  sprintf(
      msg,
      "Error in buf_set_row: Can't set the row in buffer. row_index is invalid. |row_index %d is bigger or equal to row count(buf->rows) of buf, %d|\n",
      row_index,
      buf->rows);

  libtui_error_throw(libtui_error_create(msg));
}

void buff_errs_throw_invalid_row_len(buf* buf, int row_len) {
  char* msg;
  sprintf(
      msg,
      "Error in buf_set_row: Can't set the row in buffer. input \"row\" is invalid. |strlen(row) %d > buf->columns %d|",
      row_len,
      buf->columns);

  libtui_error_throw(libtui_error_create(msg));
}

void buff_errs_throw_negative_x(buf* buf, int x) {
  char* msg;
  sprintf(msg, "Error in buf_set: x %d, is smaller than 0. x and y should be bigger than 0", x);

  libtui_error_throw(libtui_error_create(msg));
}

void buff_errs_throw_negative_y(buf* buf, int y) {
  char* msg;
  sprintf(msg, "Error in buf_set: y %d, is smaller than 0. x and y should be bigger than 0", y);

  libtui_error_throw(libtui_error_create(msg));
}

void buff_errs_throw_invalid_x(buf* buf, int x) {
  char* msg;
  sprintf(msg,
          "Error in buf_set: x %d, is invalid. x %d must be smaller than buf->columns %d",
          x,
          x,
          buf->columns);

  libtui_error_throw(libtui_error_create(msg));
}

void buff_errs_throw_invalid_y(buf* buf, int y) {
  char* msg;
  sprintf(msg,
          "Error in buf_set: y %d, is invalid. y %d must be smaller than buf->rows %d",
          y,
          y,
          buf->rows);

  libtui_error_throw(libtui_error_create(msg));
}
