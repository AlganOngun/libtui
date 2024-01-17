#include <stdio.h>
#include <termios.h>
#include <unistd.h>

#include "../lib/libtui.h"

int main(int argc, char *argv[])
{
	struct libtui_renderer *r = libtui_renderer_create(80, 30);

	libtui_draw_clear_with_char(r, '_');

	size_t x = 0;
	size_t y = 0;

	libtui_true_clear();

	libtui_hide_cursor();

	while (1) {
		if (libtui_keyboard_is_kb_hit()) {
			enum LIBTUI_KEYCODE key = libtui_keyboard_get_key();
			if (key == KEY_J) {
				++y;
			} else if (key == KEY_K) {
				--y;
			} else if (key == KEY_H) {
				--x;
			} else if (key == KEY_L) {
				++x;
			} else if (key == KEY_ESC) {
				break;
			}
		}
		libtui_draw_single_char(r, 'F', x, y);
		libtui_renderer_render(r);
	}

	libtui_show_cursor();

	libtui_renderer_free(r);

	return 0;
}
