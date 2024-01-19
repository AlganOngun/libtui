#include <stdio.h>

#include "../lib/libtui.h"

void cleanup()
{
	libtui_show_cursor();
}

void rerr(enum LIBTUI_RENDERER_ERR res)
{
	if (res != RENDERER_ERROR_OK) {
		fprintf(stderr, "Error: %s\n", libtui_renderer_err_str(res));
		cleanup();
		exit(-1);
	}
}

void derr(enum LIBTUI_DRAW_ERR res)
{
	if (res != DRAW_ERROR_OK) {
		fprintf(stderr, "Error: %s\n", libtui_draw_err_str(res));
		exit(-2);
	}
}

int main(int argc, char *argv[])
{
	atexit(cleanup);
	struct libtui_renderer *r = NULL;
	rerr(libtui_renderer_create(50, 22, &r));

	derr(libtui_draw_clear_with_char(r, '_'));

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

		derr(libtui_draw_single_char(r, 'F', x, y));
		rerr(libtui_renderer_render(r));
	}

	libtui_show_cursor();

	rerr(libtui_renderer_free(r));

	return 0;
}
