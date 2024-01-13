#ifndef BUFFERING_H
#define BUFFERING_H

// A struct that represents a 2D buffer
// Create one with buf_create(row, column) function
// Client must free the buf with buf_free
typedef struct {
  int rows;
  int columns;
  char* buf;
} buf;

// Allocates and returns owned pointer to the buf struct
// Client must free the buf using void "buf_free(buf* buf)"
buf* buf_create(int row, int column);

// Sets the row with the row_index
// "row" string's length must be equal to buf->column
// Might throw and error and exit the program
// Safe to use will terminate the program with an error
void buf_set_row(buf* buf, const char* row, int row_index);

// Frees the buf and the buffer inside it
// Must be called by client
void buf_free(buf* buf);

#endif
