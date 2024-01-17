#ifndef LIBTUI_RENDERER_H
#define LIBTUI_RENDERER_H

#include "libtui_buffering.h"

/*
* Struct that holds data used by rendering functionality.
* Sole owner of the buf* b.
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
* Create struct libtui_renderer with the given dimensions.
* Created struct libtui_renderer will allocate a buf* b and will handle it.
* Client must free the struct libtui_renderer with libtui_renderer_free.
*/
struct libtui_renderer *libtui_renderer_create(size_t width, size_t height);

/*
* Renders the final buffer to the screen
*/
void libtui_renderer_render(struct libtui_renderer *renderer);

/*
* Frees the renderer and the buf* b inside.
* After calling this, don't use any pointer to the struct libtui_buffer or the char* inside because they will be
* freed.
*/
void libtui_renderer_free(struct libtui_renderer *renderer);

#endif
