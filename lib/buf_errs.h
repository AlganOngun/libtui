#ifndef BUF_ERRS_H
#define BUF_ERRS_H

#include "buffering.h"

// Throws an error to STDERR with a message about invalid row
void buff_errs_throw_invalid_row(const buf* buf, size_t row_index);

// Throws an error to STDERR with a message about invalid row length
void buff_errs_throw_invalid_row_len(const buf* buf, size_t row_len);

// Throws an error to STDERR with a message about negative x
void buff_errs_throw_negative_x(const buf* buf, size_t x);

// Throws an error to STDERR with a message about negative y
void buff_errs_throw_negative_y(const buf* buf, size_t y);

// Throws an error to STDERR with a message about invalid x
void buff_errs_throw_invalid_x(const buf* buf, size_t x);

// Throws an error to STDERR with a message about invalid y
void buff_errs_throw_invalid_y(const buf* buf, size_t y);

#endif
