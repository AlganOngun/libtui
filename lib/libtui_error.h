#ifndef LIBTUI_ERROR_H
#define LIBTUI_ERROR_H

#include <stdbool.h>

typedef struct {
	const char *msg;
} libtui_error;

// Creates an libtui_error from string literal
libtui_error libtui_error_create(const char *msg);

// Throws an error to STDERR and terminates the program.
void libtui_error_throw(libtui_error e);

// Throws an error to STDERR and terminates the program if condition is true
// If conditon is false does nothing and returns
void libtui_error_assert(bool condition, libtui_error e);

#endif
