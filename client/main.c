#include <stdio.h>
#include <termios.h>
#include <unistd.h>

#include "../lib/libtui.h"

int main(int argc, char *argv[])
{
	enum LIBTUI_RENDERER_ERR renderer_creation_result;
	struct libtui_renderer *r =
		libtui_renderer_create(50, 22, &renderer_creation_result);
	if (renderer_creation_result != RENDERER_ERROR_OK) {
		fprintf(stderr, "Failed to create renderer, %s",
			libtui_renderer_err_str(renderer_creation_result));
		exit(-1);
	}

	enum LIBTUI_DRAW_ERR cc_res;
	libtui_draw_clear_with_char(r, '_', &cc_res);

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

		enum LIBTUI_DRAW_ERR d_res;
		libtui_draw_single_char(r, 'F', x, y, &d_res);
		enum LIBTUI_RENDERER_ERR r_res;
		libtui_renderer_render(r, &r_res);
	}

	libtui_show_cursor();

	enum LIBTUI_RENDERER_ERR res;
	libtui_renderer_free(r, &res);

	return 0;
}
