#include "libtui_renderer.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "buffering.h"
#include "libtui_draw.h"
#include "libtui_error.h"

libtui_renderer* libtui_renderer_create(size_t width, size_t height) {
  libtui_renderer* r = malloc(sizeof(libtui_renderer));
  libtui_error_assert(
      r == NULL,
      libtui_error_create(
          "Error libtui_renderer_create: couldn't allocate libtui_renderer* r. Malloc Failed!"));

  r->b = buf_create(width, height);
  r->columns = width;
  r->rows = height;
  return r;
}

void libtui_renderer_render(libtui_renderer* renderer) {
  printf("\e[1;1H\e[2J");
  fflush(stdout);
  printf("%s", renderer->b->buf);
  fflush(stdout);
  libtui_draw_clear_with(renderer, '_');
}

void libtui_renderer_free(libtui_renderer* renderer) {
  libtui_error_assert(
      renderer == NULL,
      libtui_error_create(
          "Error libtui_renderer_free: Can't free a null libtui_renderer* renderer, please try to free a valid renderer"));

  buf_free(renderer->b);
  free(renderer);
}
