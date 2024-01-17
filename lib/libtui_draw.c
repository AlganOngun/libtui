#include "libtui_draw.h"
#include "libtui_renderer.h"

#include "libtui_buffering.h"
#include "libtui_buffering_errs.h"

void libtui_draw_clear_with_char(struct libtui_renderer *renderer, const char c)
{
	for (size_t y = 0; y < renderer->rows; ++y) {
		for (size_t x = 0; x < renderer->columns; ++x) {
			if (libtui_buffer_set(renderer->buf, c, x, y) !=
			    BUFFERING_ERROR_OK) {
				// Print an error message to stderr and exit the program.
				exit(-10);
			}
		}
	}
}

void libtui_draw_clear(struct libtui_renderer *renderer)
{
	libtui_draw_clear_with_char(renderer, ' ');
}

void libtui_draw_single_char(struct libtui_renderer *renderer, const char c,
			     size_t x, size_t y)
{
	libtui_buffer_set(renderer->buf, c, x, y);
}
