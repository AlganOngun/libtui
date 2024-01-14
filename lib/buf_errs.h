#ifndef BUF_ERRS_H
#define BUF_ERRS_H

#include "buffering.h"

// Throws an error to STDERR with a message about invalid row
void buff_errs_throw_invalid_row(buf* buf, int row_index);

// Throws an error to STDERR with a message about invalid row length
void buff_errs_throw_invalid_row_len(buf* buf, int row_len);

// Throws an error to STDERR with a message about negative x
void buff_errs_throw_negative_x(buf* buf, int x);

// Throws an error to STDERR with a message about negative y
void buff_errs_throw_negative_y(buf* buf, int y);

// Throws an error to STDERR with a message about invalid x
void buff_errs_throw_invalid_x(buf* buf, int x);

// Throws an error to STDERR with a message about invalid y
void buff_errs_throw_invalid_y(buf* buf, int y);

#endif
