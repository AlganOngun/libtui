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
		"RENDERER_ERROR_BUFFER_CREATE_FAILED",
		"RENDERER_ERROR_BUFFER_FREE_FAILED",
	};

	const char *err_str = NULL;

	if (err >= RENDERER_ERROR_COUNT)
		err_str = NULL;

	err_str = LIBTUI_RENDERER_ERR_STR[err];
	return err_str;
}

struct libtui_renderer *libtui_renderer_create(size_t width, size_t height,
					       enum LIBTUI_RENDERER_ERR *result)
{
	struct libtui_renderer *r = malloc(sizeof(*r));
	if (r == NULL) {
		*result = RENDERER_ERROR_MALLOC_FAILED;
		goto return_null;
	}

	enum LIBTUI_BUFFER_ERR buf_create_result;
	r->buf = libtui_buffer_create(width, height, &buf_create_result);
	if (buf_create_result != BUFFER_ERROR_OK) {
		fprintf(stderr,
			"Error libtui_renderer_create, libtui_buffer_create: Failed to create buffer. ERROR_CODE: %s\n",
			libtui_buffer_err_str(buf_create_result));

		*result = RENDERER_ERROR_BUFFER_CREATE_FAILED;
		goto return_null_and_cleanup_renderer;
	}

	r->columns = width;
	r->rows = height;
	*result = RENDERER_ERROR_OK;
	return r;

return_null:
	return NULL;

return_null_and_cleanup_renderer:
	free(r);
	return NULL;
}

void libtui_renderer_render(struct libtui_renderer *renderer,
			    enum LIBTUI_RENDERER_ERR *result)
{
	// If the function doesn't error check
	enum LIBTUI_RENDERER_ERR dummy_res;
	if (result == NULL)
		result = &dummy_res;

	if (renderer == NULL) {
		*result = RENDERER_ERROR_NULL_RENDERER;
		return;
	}

	printf("\e[?25l\033[0;0H%s", renderer->buf->buf);
	fflush(stdout);

	// Didn't error check because any error is impossible
	// enum LIBTUI_DRAW_ERR draw_clear_with_char_result;
	libtui_draw_clear_with_char(renderer, '_', NULL);

	*result = RENDERER_ERROR_OK;
}

void libtui_renderer_free(struct libtui_renderer *renderer,
			  enum LIBTUI_RENDERER_ERR *result)
{
	// If the functin doesn't error check
	enum LIBTUI_RENDERER_ERR dummy_res;
	if (result == NULL)
		result = &dummy_res;

	if (renderer == NULL) {
		*result = RENDERER_ERROR_NULL_RENDERER;
		goto out;
	}

	enum LIBTUI_BUFFER_ERR buf_free_result;
	libtui_buffer_free(renderer->buf, &buf_free_result);
	if (buf_free_result != BUFFER_ERROR_OK) {
		fprintf(stderr,
			"Error libtui_renderer_free, libtui_buffer_free: Something went wrong in libtui_buffer_free. ERROR_CODE: %s\n",
			libtui_buffer_err_str(buf_free_result));

		*result = RENDERER_ERROR_BUFFER_FREE_FAILED;
		goto out;
	}

	*result = RENDERER_ERROR_OK;
	free(renderer);

out:
	return;
}
