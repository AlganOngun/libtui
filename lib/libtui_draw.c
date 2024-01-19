#include "libtui_draw.h"
#include "libtui_renderer.h"

#include "libtui_buffer.h"
#include <stdio.h>

const char *libtui_draw_err_str(enum LIBTUI_DRAW_ERR err)
{
	const char *LIBTUI_DRAW_ERR_STR[] = {
		"DRAW_ERROR_OK",
		"DRAW_ERROR_NULL_RENDERER",
		"DRAW_ERROR_INVALID_DIMENSIONS",
	};

	const char *err_str = NULL;

	if (err < RENDERER_ERROR_COUNT)
		err_str = LIBTUI_DRAW_ERR_STR[err];

	return err_str;
}

#define RETURN_DEFER(err)       \
	do {                    \
		result = (err); \
		goto defer;     \
	} while (0);

enum LIBTUI_DRAW_ERR
libtui_draw_clear_with_char(struct libtui_renderer *renderer, const char c)
{
	enum LIBTUI_DRAW_ERR result = DRAW_ERROR_OK;
	if (renderer == NULL)
		RETURN_DEFER(DRAW_ERROR_NULL_RENDERER);

	{
		for (size_t y = 0; y < renderer->rows; ++y) {
			for (size_t x = 0; x < renderer->columns; ++x) {
				libtui_buffer_set(renderer->buf, c, x, y);
			}
		}
	}

defer:
	return result;
}

enum LIBTUI_DRAW_ERR libtui_draw_clear(struct libtui_renderer *renderer)
{
	enum LIBTUI_DRAW_ERR result = DRAW_ERROR_OK;

	{
		result = libtui_draw_clear_with_char(renderer, ' ');
	}

	return result;
}

enum LIBTUI_DRAW_ERR libtui_draw_single_char(struct libtui_renderer *renderer,
					     const char c, size_t x, size_t y)
{
	enum LIBTUI_DRAW_ERR result = DRAW_ERROR_OK;
	if (renderer == NULL)
		RETURN_DEFER(DRAW_ERROR_NULL_RENDERER);
	if (x >= renderer->columns || y >= renderer->rows)
		RETURN_DEFER(DRAW_ERROR_INVALID_DIMENSIONS);
	if (x < 0 || y < 0)
		RETURN_DEFER(DRAW_ERROR_INVALID_DIMENSIONS);

	{
		libtui_buffer_set(renderer->buf, c, x, y);
	}

defer:
	return result;
}
