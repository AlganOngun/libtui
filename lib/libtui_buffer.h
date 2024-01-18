#ifndef LIBTUI_BUFFER_H
#define LIBTUI_BUFFER_H

#include <stdlib.h>

/*
 * Error Codes For Buffer Module
 */
enum LIBTUI_BUFFER_ERR {
	// No Error
	BUFFER_ERROR_OK = 0,
	// Either x or y is bigger than the respective buffer dimension.
	BUFFER_ERROR_INVALID_DIMENSION,
	// Tried to use malloc but failed
	BUFFER_ERROR_MALLOC_FAILED,
	// The buf* passed in as an argument is NULL
	BUFFER_ERROR_NULL_BUF,
	// The buf->buf is NULL. the const char* buf inside libtui_buffer->buf is NULL
	BUFFER_ERROR_NULL_BUF_BUFFER,

	// Total number of errors
	BUFFER_ERROR_COUNT,
};

/*
 * This function returns the string that corresponds to the given LIBTUI_BUFFER_ERR
 */
const char *libtui_buffer_err_str(enum LIBTUI_BUFFER_ERR err);

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
* Returns the result code with "enum LIBTUI_BUFFER_ERR *result".
* Will return NULL when something goes bad so ALWAYS CHECK FOR NULL AND THE result pointer.
* Returns the result of the function with enum LIBTUI_BUFFER_ERR *result.
*/
struct libtui_buffer *libtui_buffer_create(size_t column, size_t row,
					   enum LIBTUI_BUFFER_ERR *result);

/*
* Gets x, y positions and maps them according to the buf which is 1-Dimensional.
* Returns the corresponding index in 1-Dimensional buffer.
* Returns the result code with "enum LIBTUI_BUFFER_ERR *result".
* Will return 0 (which is the origin) when something goes bad.
* Returns the result of the function with enum LIBTUI_BUFFER_ERR *result.
*/
size_t libtui_buffer_get_index(const struct libtui_buffer *buf, size_t x,
			       size_t y, enum LIBTUI_BUFFER_ERR *result);

/*
* Sets the char at a specific location.
* The origin is top-left.
* Returns the result of the function with enum LIBTUI_BUFFER_ERR *result.
*/
void libtui_buffer_set(struct libtui_buffer *buf, const char c, size_t x,
		       size_t y, enum LIBTUI_BUFFER_ERR *result);

/*
* Gets the char at a specific location.
* The origin is top-left.
* Pass LIBTUI_BUFFER_ERR *result to get the result of the function.
* Returns '\0' in case of an error.
* Returns the result of the function with enum LIBTUI_BUFFER_ERR *result.
*/
char libtui_buffer_get(const struct libtui_buffer *buf, size_t x, size_t y,
		       enum LIBTUI_BUFFER_ERR *result);

/*
* Frees the struct libtui_buffer and the buffer inside it.
* Must be called by client.
* Dont't use any pointers to the struct libtui_buffer neither the char* buf inside it.
* Returns the result of the function with enum LIBTUI_BUFFER_ERR *result.
*/
void libtui_buffer_free(struct libtui_buffer *buf,
			enum LIBTUI_BUFFER_ERR *result);

#endif
