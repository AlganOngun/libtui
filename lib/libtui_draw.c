#include "libtui_draw.h"

#include "libtui_buffering.h"

void libtui_draw_clear_with(libtui_renderer* renderer, const char c) {
  for (size_t y = 0; y < renderer->rows; ++y) {
    for (size_t x = 0; x < renderer->columns; ++x) {
      buf_set(renderer->b, c, x, y);
    }
  }
}

void libtui_draw_clear(libtui_renderer* renderer) {
  libtui_draw_clear_with(renderer, ' ');
}

void libtui_draw_single_char(libtui_renderer* renderer, const char c, size_t x, size_t y) {
  buf_set(renderer->b, c, x, y);
}
