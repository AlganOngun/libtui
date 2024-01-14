#include "libtui_renderer.h"

#include <stdio.h>
#include <stdlib.h>

#include "buffering.h"
#include "libtui_error.h"

libtui_renderer* libtui_renderer_create(size_t width, size_t height) {
  libtui_renderer* r = malloc(sizeof(libtui_renderer));
  libtui_error_throw_condition(
      r == NULL,
      libtui_error_create(
          "Error libtui_renderer_create: couldn't allocate libtui_renderer* r. Malloc Failed!"));

  r->b = buf_create(width, height);
  return r;
}

void libtui_renderer_free(libtui_renderer* renderer) {
  libtui_error_throw_condition(
      renderer == NULL,
      libtui_error_create(
          "Error libtui_renderer_free: Can't free a null libtui_renderer* renderer, please try to free a valid renderer"));

  buf_free(renderer->b);
  free(renderer);
}