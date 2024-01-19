#ifndef LIBTUI_DRAW_H
#define LIBTUI_DRAW_H

#include <stdlib.h>

struct libtui_renderer;

/*! \defgroup draw Draw
 * All the things about the draw module
 *  \{
 */

/*! \file libtui_draw.h
 *  \brief The group of functions that provide a nice interface for the client to draw to screen
 */

/*! \enum LIBTUI_DRAW_ERR
 *  \brief Error Codes For Draw Module
 */
enum LIBTUI_DRAW_ERR {
	//! No Error
	DRAW_ERROR_OK = 0,
	//! The libtui_renderer* passed in as an argument is NULL
	DRAW_ERROR_NULL_RENDERER,
	//! The dimensions that were passed to the function were invalid
	DRAW_ERROR_INVALID_DIMENSIONS,

	//! Count of errors
	DRAW_ERROR_COUNT,
};

/*! \fn const char *libtui_draw_err_str(enum LIBTUI_DRAW_ERR err).
 *  \brief This function returns the string that corresponds to the given LIBTUI_DRAW_ERR
 *
 *  \param err The error code to get the correspinding string.
 */
const char *libtui_draw_err_str(enum LIBTUI_DRAW_ERR err);

/*! \fn enum LIBTUI_DRAW_ERR libtui_draw_clear_with_char(struct libtui_renderer *const renderer, const char c).
*   \brief Clears the screen with the specified char.
*
* example: if c == 'X': whole screen will be made up of 'X' chars.
*
*   \param renderer The renderer to clear.
*   \param c The char to clear with.
*
*   \return Return an enum LIBTUI_DRAW_ERR as the function result;
*/
enum LIBTUI_DRAW_ERR
libtui_draw_clear_with_char(struct libtui_renderer *const renderer,
			    const char c);

/*! \fn enum LIBTUI_DRAW_ERR libtui_draw_clear(struct libtui_renderer *const renderer).
*   \brief Clears the screen.
*
* Clears the screen with ' '.
*
*   \param renderer The renderer to clear
*
*   \return Returns an enum LIBTUI_DRAW_ERR as the function result;
*/
enum LIBTUI_DRAW_ERR libtui_draw_clear(struct libtui_renderer *const renderer);

/*! \fn enum LIBTUI_DRAW_ERR libtui_draw_single_char(struct libtui_renderer *const renderer, const char c, size_t x, size_t y);
*   \brief Draws a single char at the specified (x, y).
*
* The origin of the screen is top-left.
*
*   \param renderer The renderer to draw to.
*   \param c The char to draw.
*   \param x The x position of the draw position.
*   \param y The y position of the draw position.
*
*   \return Returns an enum LIBTUI_DRAW_ERR as the function result;
*/
enum LIBTUI_DRAW_ERR
libtui_draw_single_char(struct libtui_renderer *const renderer, const char c,
			size_t x, size_t y);

/*! \example simple.c
 * This is an example demonstrating libtui_draw, libtui_renderer, libtui_keyboard and libtui_term_control modules with an example of how to handle errors properly.
 */

//! \}

#endif
