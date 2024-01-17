#ifndef BUFFERING_H
#define BUFFERING_H

#include <stdlib.h>

enum LIBTUI_BUFFERING_ERR;

/* A struct that represents a 2D buffer.
* Create one with buf_create(row, column) function.
* struct libtui_buffer owns the char* buf and will free it when buf_free is called
* Client must free the struct libtui_buffer with buf_free.
*/
struct libtui_buffer {
	char *buf; // Owned by libtui_buffer
	size_t rows;
	size_t columns;
};

/*
* Allocates and returns owned pointer to the struct libtui_buffer struct.
* Client must free the struct libtui_buffer using void "buf_free(buf* buf)".
* Returns the result code with "enum LIBTUI_BUFFERING_ERR *result".
* Will return NULL when something goes bad so ALWAYS CHECK FOR NULL AND THE result pointer.
*/
struct libtui_buffer *buf_create(size_t column, size_t row,
				 enum LIBTUI_BUFFERING_ERR *result);

/*
* Gets x, y positions and maps them according to the buf which is 1-Dimensional.
* Returns the corresponding index in 1-Dimensional buffer.
* Returns the result code with "enum LIBTUI_BUFFERING_ERR *result".
* Will return 0 (which is the origin) when something goes bad.
*/
size_t libtui_buffer_get_index(const struct libtui_buffer *buf, size_t x,
			       size_t y, enum LIBTUI_BUFFERING_ERR *result);

/*
* Sets the char at a specific location.
* The origin is top-left.
* Returns the result code.
*/
enum LIBTUI_BUFFERING_ERR libtui_buffer_set(struct libtui_buffer *buf,
					    const char c, size_t x, size_t y);

/*
* Gets the char at a specific location.
* The origin is top-left.
* Pass LIBTUI_BUFFERING_ERR *result to get the result of the function.
* Returns '\0' in case of an error.
*/
char libtui_buffer_get(const struct libtui_buffer *buf, size_t x, size_t y,
		       enum LIBTUI_BUFFERING_ERR *result);

/*
* Frees the struct libtui_buffer and the buffer inside it.
* Must be called by client.
* Dont't use any pointers to the struct libtui_buffer neither the char* buf inside it.
* Returns the result of the function with enum LIBTUI_BUFFERING_ERR.
*/
enum LIBTUI_BUFFERING_ERR libtui_buffer_free(struct libtui_buffer *buf);

#endif
