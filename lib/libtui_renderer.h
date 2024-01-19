#ifndef LIBTUI_RENDERER_H
#define LIBTUI_RENDERER_H

#include <stdlib.h>

struct libtui_buffer;

/*! \defgroup renderer Renderer
 * All the things about the libtui_renderer and the renderer module
 *  \{
 */

/*! \file libtui_renderer.h
 *  \brief The magical part that handles the libtui_buffer and screen
 */

/*! \enum LIBTUI_RENDERER_ERR
 * Error Codes For Renderer Module
 */
enum LIBTUI_RENDERER_ERR {
	//! No Error
	RENDERER_ERROR_OK = 0,
	//! Tried to use malloc but failed
	RENDERER_ERROR_MALLOC_FAILED,
	//! The libtui_renderer* passed in as an argument is NULL
	RENDERER_ERROR_NULL_RENDERER,

	//! Total number of errors
	RENDERER_ERROR_COUNT,
};

/*! \fn const char *libtui_renderer_err_str(enum LIBTUI_RENDERER_ERR err);
 *  \brief This function returns the string that corresponds to the given LIBTUI_RENDERER_ERR
 *  \param err The error code to get the correspinding string.
 */
const char *libtui_renderer_err_str(enum LIBTUI_RENDERER_ERR err);

/*! \struct libtui_renderer
*   \brief Struct that holds data used by therendering module.
*
* Create this struct with libtui_renderer_create. Don't try creating it manually.
* Client must free an instance using libtui_renderer_free.
*/
struct libtui_renderer {
	//! Owned and will be freed together with struct libtui_renderer at libtui_renderer_free.
	struct libtui_buffer *buf;
	//! The amount of chars in the X axis on screen doesn't include '\n' and such control chars.
	size_t rows;
	//! The amount of chars in the Y axis on screen doesn't include '\n' and such control chars.
	size_t columns;
};

/*! \fn enum LIBTUI_RENDERER_ERR libtui_renderer_create(size_t width, size_t height, struct libtui_renderer **renderer_out).
*   \brief Creates a new libtui_renderer.
*
* Client must free the struct libtui_renderer with libtui_renderer_free.
*
* \param width The width of the screen that the renderer will work on
* \param height The height of the screen that the renderer will work on
*
* \return Returns the created renderer in struct libtui_renderer **const renderer_out parameter.
* \return Returns an enum LIBTUI_RENDERER_ERR as the function result.
*/
enum LIBTUI_RENDERER_ERR
libtui_renderer_create(size_t width, size_t height,
		       struct libtui_renderer **const renderer_out);

/*! \fn enum LIBTUI_RENDERER_ERR libtui_renderer_render(struct libtui_renderer *const renderer).
*  \brief Renders the final buffer to the screen.
*
*  \param renderer The struct libtui_renderer to render to screen.
*
*  \return Returns an enum LIBTUI_RENDERER_ERR as the function result.
*/
enum LIBTUI_RENDERER_ERR
libtui_renderer_render(struct libtui_renderer *const renderer);

/*! \fn enum LIBTUI_RENDERER_ERR libtui_renderer_free(struct libtui_renderer *renderer).
*   \brief Frees the renderer completely
*
* After calling this, don't use any pointer to the struct libtui_buffer or the char* inside because they will be freed.
*
*   \param renderer The strcut libtui_renderer to free
*
*   \return Returns an enum LIBTUI_RENDERER_ERR as the function result.
*/
enum LIBTUI_RENDERER_ERR libtui_renderer_free(struct libtui_renderer *renderer);

/*! \example simple.c
 * This is an example demonstrating libtui_draw, libtui_renderer, libtui_keyboard and libtui_term_control modules with an example of how to handle errors properly.
 */

//! \}

#endif
