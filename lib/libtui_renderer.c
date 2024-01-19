#include "libtui_renderer.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "libtui_buffer.h"
#include "libtui_draw.h"

const char *libtui_renderer_err_str(enum LIBTUI_RENDERER_ERR err)
{
	const char *LIBTUI_RENDERER_ERR_STR[] = {
		"RENDERER_ERROR_OK",
		"RENDERER_ERROR_MALLOC_FAILED",
		"RENDERER_ERROR_NULL_RENDERER",
	};

	const char *err_str = NULL;

	if (err < RENDERER_ERROR_COUNT)
		err_str = LIBTUI_RENDERER_ERR_STR[err];

	return err_str;
}

#define RETURN_DEFER(err)       \
	do {                    \
		result = (err); \
		goto defer;     \
	} while (0);

enum LIBTUI_RENDERER_ERR
libtui_renderer_create(size_t width, size_t height,
		       struct libtui_renderer **renderer_out)
{
	enum LIBTUI_RENDERER_ERR result = RENDERER_ERROR_OK;
	struct libtui_renderer *r;

	{
		r = malloc(sizeof(*r));
		if (r == NULL)
			RETURN_DEFER(RENDERER_ERROR_MALLOC_FAILED);

		r->buf = libtui_buffer_create(width, height);
		if (r->buf == NULL)
			RETURN_DEFER(RENDERER_ERROR_MALLOC_FAILED);

		r->columns = width;
		r->rows = height;
	}

defer:
	*renderer_out = r;
	return result;
}

enum LIBTUI_RENDERER_ERR
libtui_renderer_render(struct libtui_renderer *renderer)
{
	enum LIBTUI_RENDERER_ERR result = RENDERER_ERROR_OK;
	if (renderer == NULL)
		RETURN_DEFER(RENDERER_ERROR_NULL_RENDERER);

	{
		printf("\e[?25l\033[0;0H%s", renderer->buf->buf);
		fflush(stdout);

		libtui_draw_clear_with_char(renderer, '_');
	}

defer:
	return result;
}

enum LIBTUI_RENDERER_ERR libtui_renderer_free(struct libtui_renderer *renderer)
{
	enum LIBTUI_RENDERER_ERR result = RENDERER_ERROR_OK;
	if (renderer == NULL)
		RETURN_DEFER(RENDERER_ERROR_NULL_RENDERER);

	{
		libtui_buffer_free(renderer->buf);
		free(renderer);
	}

defer:
	return result;
}
