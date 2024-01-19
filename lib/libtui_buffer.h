#ifndef LIBTUI_BUFFER_H
#define LIBTUI_BUFFER_H

#include <stdlib.h>

/* A struct that represents a 2D buffer.
* Create one with buf_create(row, column) function.
* struct libtui_buffer owns the char* buf and will free it when buf_free is called
* Caller must free the struct libtui_buffer with buf_free.
* WARNING: Internal struct, end user shouldn't use this
*/
struct libtui_buffer {
	char *buf; // Owned by libtui_buffer
	size_t rows;
	size_t columns;
};

/*
* Allocates and returns owned pointer to the struct libtui_buffer struct.
* Caller must free the struct libtui_buffer using void "buf_free(buf* buf)".
* Will return NULL if malloc fails(pretty unlikely), so this is a function the caller can use without worrying.
* WARNING: Internal function, end user shouldn't use this
*/
struct libtui_buffer *libtui_buffer_create(size_t column, size_t row);

/*
* Gets x, y positions and maps them according to the buf which is 1-Dimensional.
* Returns the corresponding index in 1-Dimensional buffer.
* WARNING: Internal Funcion, end user shouldn't use this
* Returns 0 (origin) when something goes bad.
*/
size_t libtui_buffer_get_index(const struct libtui_buffer *buf, size_t x,
			       size_t y);

/*
* Sets the char at a specific location.
* The origin is top-left.
* WARNING: Internal Funcion, end user shouldn't use this
*/
void libtui_buffer_set(struct libtui_buffer *buf, const char c, size_t x,
		       size_t y);

/*
* Gets the char at a specific location.
* The origin is top-left.
* Returns '\0' in case of an error.
* WARNING: Internal Funcion, end user shouldn't use this
*/
char libtui_buffer_get(const struct libtui_buffer *buf, size_t x, size_t y);

/*
* Frees the struct libtui_buffer and the buffer inside it.
* Must be called.
* Dont't use any pointers to the struct libtui_buffer neither the char* buf inside it.
* WARNING: Internal Funcion, end user shouldn't use this
*/
void libtui_buffer_free(struct libtui_buffer *buf);

#endif
