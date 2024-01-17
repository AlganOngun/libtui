#include "libtui_renderer.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "libtui_buffering.h"
#include "libtui_draw.h"
#include "libtui_error.h"

struct libtui_renderer *libtui_renderer_create(size_t width, size_t height)
{
	struct libtui_renderer *r = malloc(sizeof(*r));
	libtui_error_assert(
		r == NULL,
		libtui_error_create(
			"Error libtui_renderer_create: couldn't allocate libtui_renderer* r. Malloc Failed!"));

	r->buf = buf_create(width, height);
	r->columns = width;
	r->rows = height;
	return r;
}

void libtui_renderer_render(struct libtui_renderer *renderer)
{
	printf("\e[?25l\033[0;0H%s", renderer->buf->buf);
	fflush(stdout);
	libtui_draw_clear_with_char(renderer, '_');
}

void libtui_renderer_free(struct libtui_renderer *renderer)
{
	libtui_error_assert(
		renderer == NULL,
		libtui_error_create(
			"Error libtui_renderer_free: Can't free a null libtui_renderer* renderer, please try to free a valid renderer"));

	libtui_buffer_free(renderer->buf);
	free(renderer);
}
