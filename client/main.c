#include <stdio.h>
#include <termios.h>
#include <unistd.h>

#include "../lib/libtui.h"

int main(int argc, char* argv[]) {
  libtui_renderer* r = libtui_renderer_create(10, 5);

  libtui_draw_clear_with(r, '_');

  size_t x = 0;
  size_t y = 0;
  while (1) {
    if (libtui_keyboard_is_kb_hit()) {
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
    }
    libtui_draw_single_char(r, 'Y', x, y);
    libtui_renderer_render(r);
    sleep(0.1);
  }

  libtui_renderer_free(r);

  return 0;
}
