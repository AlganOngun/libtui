#ifndef LIBTUI_RENDERER_H
#define LIBTUI_RENDERER_H

#include "buffering.h"

// Struct that holds data used by rendering functionality..
// Sole owner of the buf* b.
// Client must free an instance using libtui_renderer_free.
typedef struct {
  buf* b;  // Owned and will be freed together with libtui_renderer at libtui_renderer_free.
} libtui_renderer;

// Creates a new libtui_renderer.
// Create libtui_renderer with the given dimensions.
// Created libtui_renderer will allocate a buf* b and will handle it.
// Client must free the libtui_renderer with libtui_renderer_free.
libtui_renderer* libtui_renderer_create(size_t width, size_t height);

// Frees the renderer and the buf* b inside.
// After calling this, don't use any pointer to the buf or the char* inside because they will be
// freed.
void libtui_renderer_free(libtui_renderer* renderer);

#endif
