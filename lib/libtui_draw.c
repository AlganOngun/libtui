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
		"DRAW_ERROR_BUFFER_SET_FAILED",
	};

	const char *err_str = NULL;

	if (err >= RENDERER_ERROR_COUNT)
		err_str = NULL;

	err_str = LIBTUI_DRAW_ERR_STR[err];
	return err_str;
}

void libtui_draw_clear_with_char(struct libtui_renderer *renderer, const char c,
				 enum LIBTUI_DRAW_ERR *result)
{
	// If function doesn't error check
	enum LIBTUI_DRAW_ERR dummy_res;
	if (result == NULL)
		result = &dummy_res;

	if (renderer == NULL) {
		*result = DRAW_ERROR_NULL_RENDERER;
		goto out;
	}

	for (size_t y = 0; y < renderer->rows; ++y) {
		for (size_t x = 0; x < renderer->columns; ++x) {
			enum LIBTUI_BUFFER_ERR buffer_set_result;
			libtui_buffer_set(renderer->buf, c, x, y,
					  &buffer_set_result);

			if (buffer_set_result != BUFFER_ERROR_OK) {
				fprintf(stderr,
					"Error draw_clear_with_char, libtui_buffer_set: Failed to set to buffer. ERROR_CODE: %s",
					libtui_buffer_err_str(
						buffer_set_result));

				*result = DRAW_ERROR_BUFFER_SET_FAILED;
				goto out;
			}
		}
	}

	*result = DRAW_ERROR_OK;

out:
	return;
}

void libtui_draw_clear(struct libtui_renderer *renderer,
		       enum LIBTUI_DRAW_ERR *result)
{
	enum LIBTUI_DRAW_ERR draw_clear_with_char_result;
	libtui_draw_clear_with_char(renderer, ' ',
				    &draw_clear_with_char_result);

	*result = draw_clear_with_char_result;
}

void libtui_draw_single_char(struct libtui_renderer *renderer, const char c,
			     size_t x, size_t y, enum LIBTUI_DRAW_ERR *result)
{
	// If function doesn't error check
	enum LIBTUI_DRAW_ERR dummy_res;
	if (result == NULL)
		result = &dummy_res;

	if (renderer == NULL) {
		*result = DRAW_ERROR_NULL_RENDERER;
		goto out;
	}

	enum LIBTUI_BUFFER_ERR buffer_set_result;
	libtui_buffer_set(renderer->buf, c, x, y, &buffer_set_result);
	if (buffer_set_result != BUFFER_ERROR_OK)
		*result = DRAW_ERROR_BUFFER_SET_FAILED;

	*result = DRAW_ERROR_OK;

out:
	return;
}
