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
* Returns the created renderer in struct libtui_renderer *const renderer_out parameter.
* Returns an enum LIBTUI_RENDERER_ERR as the function result.
*/
enum LIBTUI_RENDERER_ERR
libtui_renderer_create(size_t width, size_t height,
		       struct libtui_renderer **renderer_out);

/*
* Renders the final buffer to the screen.
* Returns an enum LIBTUI_RENDERER_ERR as the function result.
*/
enum LIBTUI_RENDERER_ERR
libtui_renderer_render(struct libtui_renderer *renderer);

/*
* Frees the renderer completely
* After calling this, don't use any pointer to the struct libtui_buffer or the char* inside because they will be
* freed.
* Returns an enum LIBTUI_RENDERER_ERR as the function result.
*/
enum LIBTUI_RENDERER_ERR libtui_renderer_free(struct libtui_renderer *renderer);

#endif
