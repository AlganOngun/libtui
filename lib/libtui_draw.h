#ifndef LIBTUI_DRAW_H
#define LIBTUI_DRAW_H

#include <stdlib.h>

struct libtui_renderer;

/*
 * Error Codes For Draw Module
 */
enum LIBTUI_DRAW_ERR {
	// No Error
	DRAW_ERROR_OK = 0,
	// The libtui_renderer* passed in as an argument is NULL
	DRAW_ERROR_NULL_RENDERER,
	// The function called libtui_buffer_set but it failed
	DRAW_ERROR_BUFFER_SET_FAILED,

	// Count of errors
	DRAW_ERROR_COUNT,
};

/*
 * This function returns the string that corresponds to the given LIBTUI_DRAW_ERR
 */
const char *libtui_draw_err_str(enum LIBTUI_DRAW_ERR err);

/*
* Clears the screen with the specified char.
* example: if c == 'X': whole screen will be made up of 'X' chars.
* Returns result of the function in enum LIBTUI_DRAW_ERR *result argument;
*/
void libtui_draw_clear_with_char(struct libtui_renderer *renderer, const char c,
				 enum LIBTUI_DRAW_ERR *result);

/*
* Clears the screen.
* Detailed Explanation: Clears the screen with ' '.
* Uses the libtui_draw_clear_with function underhood.
* Returns result of the function in enum LIBTUI_DRAW_ERR *result argument;
*/
void libtui_draw_clear(struct libtui_renderer *renderer,
		       enum LIBTUI_DRAW_ERR *result);

/*
* Draws a single char at the specified (x, y).
* The origin of the screen is top-left.
* Returns result of the function in enum LIBTUI_DRAW_ERR *result argument;
*/
void libtui_draw_single_char(struct libtui_renderer *renderer, const char c,
			     size_t x, size_t y, enum LIBTUI_DRAW_ERR *result);

#endif
