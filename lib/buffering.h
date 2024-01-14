#ifndef BUFFERING_H
#define BUFFERING_H

#include <stdlib.h>

// A struct that represents a 2D buffer.
// Create one with buf_create(row, column) function.
// buf owns the char* buf and will free it when buf_free is called
// Client must free the buf with buf_free.
typedef struct {
  char* buf;  // Owned by buf
  size_t rows;
  size_t columns;
} buf;

// Allocates and returns owned pointer to the buf struct.
// Client must free the buf using void "buf_free(buf* buf)".
buf* buf_create(size_t column, size_t row);

// Maps (x, y) 2D coordinate to one dimensional buf index.
// End user should'nt bother with indexes directly using this function.
// To get a char at buf use buf_get and to set a char use buf_set.
// Prefer the higher level functions like buf_set_row, buf_get, buf_set to this.
size_t buf_map_i(const buf* buf, size_t x, size_t y);

// Sets the row with the row_index.
// "row" string's length must be equal to buf->column.
// Might throw and error and exit the program.
// Safe to use will terminate the program with an error.
void buf_set_row(buf* buf, const char* row, size_t row_index);

// Sets the char at a specific location.
// The origin is top-left.
void buf_set(buf* buf, const char c, size_t x, size_t y);

// Gets the char at a specific location.
// The origin is top-left.
char buf_get(const buf* buf, size_t x, size_t y);

// Frees the buf and the buffer inside it.
// Must be called by client.
// Dont't use any pointers to the buf neither the char* buf inside it.
void buf_free(buf* buf);

#endif
