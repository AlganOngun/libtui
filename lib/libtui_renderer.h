#ifndef LIBTUI_RENDERER_H
#define LIBTUI_RENDERER_H

#include <stdlib.h>

struct libtui_buffer;

/*
 * Error Codes For Renderer Module
 */
enum LIBTUI_RENDERER_ERR {
	// No Error
	RENDERER_ERROR_OK = 0,
	// Tried to use malloc but failed
	RENDERER_ERROR_MALLOC_FAILED,
	// The libtui_renderer* passed in as an argument is NULL
	RENDERER_ERROR_NULL_RENDERER,
	// libtui_buffer_create was called from the function but it failed. Check stderr for error message.
	RENDERER_ERROR_BUFFER_CREATE_FAILED,
	// libtui_buffer_free was called from the function but it failed. Check stderr for error message.
	RENDERER_ERROR_BUFFER_FREE_FAILED,

	// Total number of errors
	RENDERER_ERROR_COUNT,
};

/*
 * This function returns the string that corresponds to the given LIBTUI_RENDERER_ERR
 */
const char *libtui_renderer_err_str(enum LIBTUI_RENDERER_ERR err);

/*
* Struct that holds data used by rendering functionality.
* Sole owner of the buf* b.
* Create this struct with libtui_renderer_create. Don't try creating it manually.
* Client must free an instance using libtui_renderer_free.
*/
struct libtui_renderer {
	struct libtui_buffer *
		buf; // Owned and will be freed together with struct libtui_renderer at libtui_renderer_free.
	size_t rows;
	size_t columns;
};

/*
* Creates a new libtui_renderer.
* Client must free the struct libtui_renderer with libtui_renderer_free.
* Will Return NULL when something goes bad.
* Returns result of the function in enum LIBTUI_RENDERER_ERR *result argument;
*/
struct libtui_renderer *
libtui_renderer_create(size_t width, size_t height,
		       enum LIBTUI_RENDERER_ERR *result);

/*
* Renders the final buffer to the screen.
* Returns result of the function in enum LIBTUI_RENDERER_ERR *result argument;
*/
void libtui_renderer_render(struct libtui_renderer *renderer,
			    enum LIBTUI_RENDERER_ERR *result);

/*
* Frees the renderer and the buf* b inside.
* After calling this, don't use any pointer to the struct libtui_buffer or the char* inside because they will be
* freed.
* Returns result of the function in enum LIBTUI_RENDERER_ERR *result argument;
*/
void libtui_renderer_free(struct libtui_renderer *renderer,
			  enum LIBTUI_RENDERER_ERR *result);

#endif
