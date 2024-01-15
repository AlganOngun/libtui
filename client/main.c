#include <stdio.h>
#include <termios.h>
#include <unistd.h>

#include "../lib/libtui.h"

int main(int argc, char* argv[]) {
  libtui_renderer* r = libtui_renderer_create(10, 5);

  libtui_draw_clear_with(r, '_');

  libtui_keyboard kb = libtui_keyboard_init();

  size_t x = 0;
  size_t y = 0;
  libtui_draw_single_char(r, 'X', x, y);
  libtui_renderer_render(r);
  while (1) {
    LIBTUI_KEYCODE key = libtui_keyboard_get_key();
    if (key == KEY_J) {
      ++y;
    } else if (key == KEY_K) {
      --y;
    } else if (key == KEY_H) {
      --x;
    } else if (key == KEY_L) {
      ++x;
    }
    libtui_draw_single_char(r, 'X', x, y);
    libtui_renderer_render(r);
  }
  libtui_keyboard_deinit(kb);

  libtui_renderer_free(r);

  return 0;
}
