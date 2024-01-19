#ifndef LIBTUI_BUFFER_H
#define LIBTUI_BUFFER_H

/*! \defgroup buffer Buffer
 * All the things aobut the libtui_buffer and the buffer module
 *  \{
 */

/*! \file libtui_buffer.h
 *  \brief A readadble and writable 2D mapped buffer in the heap.
 *  	   WARNING: Internal, end user shouldn't use this.
 *
 *  All the things that were declared in this header is internal and meant to be used by the library.
 *  If you don't know what you're doing don't use this header because it doesn't handle errors.
 */

#include <stdlib.h>

/*! \struct libtui_buffer
* \brief A struct that represents a 2D buffer.
*        WARNING: Internal struct, end user shouldn't use this
*
* Create one with libtui_buffer_create() function.
* struct libtui_buffer owns the char* buf and will free it when libtui_buffer_free is called
* Caller must free the struct libtui_buffer with libtui_buffer_free.
*/
struct libtui_buffer {
	//! Owned by libtui_buffer
	char *buf;
	size_t rows;
	size_t columns;
};

/*! \fn struct libtui_buffer *libtui_buffer_create(size_t column, size_t row)
*   \brief Allocates and returns owned pointer to the struct libtui_buffer struct.
* 	 WARNING: Internal function, end user shouldn't use this
*
*   \return Returns an strcut libtui_buffer which the caller is responsible to free using void void libtui_buffer_free(struct libtui_buffer *buf).
*           Will return NULL if malloc fails.
*
*   \param column The amount of chars it stores in the X axis. Must be bigger than 0
*   \param row The amount of chars it stores in the Y axis. Must be bigger than 0
*/
struct libtui_buffer *libtui_buffer_create(size_t column, size_t row);

/*! \fn size_t libtui_buffer_get_index(const struct libtui_buffer *const buf, size_t x, size_t y)
*   \brief Gets x, y positions and maps them according to the buf which is 1-Dimensional.
*          WARNING: Internal Funcion, end user shouldn't use this
*
*   \return Returns the corresponding index in 1-Dimensional buffer.
*  	     Returns 0 (origin) when something goes bad.
*
*   \param buf The pointer to the struct libtui_buffer that was created with struct libtui_buffer *libtui_buffer_create(size_t column, size_t row).
*              This function will neither modify the pointer or the struct.
*   \param x The x position of the wanted char.
*   \param y The y position of the wanted char.
*/
size_t libtui_buffer_get_index(const struct libtui_buffer *const buf, size_t x,
			       size_t y);

/*! \fn void libtui_buffer_set(struct libtui_buffer *const buf, const char c, size_t x, size_t y).
*   \brief Sets the char at a specific position.
* 	 WARNING: Internal Funcion, end user shouldn't use this.
*
* The origin is top-left.
*
*   \param buf The pointer to the struct libtui_buffer that was created with struct libtui_buffer *libtui_buffer_create(size_t column, size_t row).
*              This function will modify the struct passed but it won't modify the pointer.
*   \param c The char value, the char at the given position will be setted.
*   \param x The x position of the char that should be setted.
*   \param y The y position of the char that should be setted.
*/
void libtui_buffer_set(struct libtui_buffer *const buf, const char c, size_t x,
		       size_t y);

/*! \fn char libtui_buffer_get(const struct libtui_buffer *const buf, size_t x, size_t y)
*   \brief Gets the char at a specific location.
*          WARNING: Internal Funcion, end user shouldn't use this
*
* The origin is top-left.
*   \return Returns the char at given position.
*           Will return '\0' in case of an error.
*
*   \param buf The pointer to the struct libtui_buffer that was created with struct libtui_buffer *libtui_buffer_create(size_t column, size_t row).
*              This function will neither modify the pointer or the struct.
*   \param x The x position of the wanted char.
*   \param y The y position of the wanted char.
*/
char libtui_buffer_get(const struct libtui_buffer *const buf, size_t x,
		       size_t y);

/*! \fn void libtui_buffer_free(struct libtui_buffer *buf)
*   \brief Frees the struct libtui_buffer and the buffer inside it.
*          WARNING: Internal Funcion, end user shouldn't use this.
*
* Must be called by the caller.
* Dont't use any pointers to the struct libtui_buffer neither the char* buf inside it.
*
*   \param buf The pointer to the struct libtui_buffer that was created with struct libtui_buffer *libtui_buffer_create(size_t column, size_t row).
*              This function will neither modify the pointer or the struct.
*/
void libtui_buffer_free(struct libtui_buffer *buf);

//! \}

#endif
