#ifndef LIBTUI_DRAW
#define LIBTUI_DRAW

#include <stdlib.h>

#include "libtui_renderer.h"

// Clears the screen with the specified char.
// example: if c == 'X': whole screen will be made up of 'X' chars.
void libtui_draw_clear_with(libtui_renderer* renderer, const char c);

// Clears the screen.
// Detailed Explanation: Clears the screen with ' '.
// Uses the libtui_draw_clear_with function underhood.
void libtui_draw_clear(libtui_renderer* renderer);

// Draws a single char at the specified (x, y).
// The origin of the screen is top-left.
void libtui_draw_single_char(libtui_renderer* renderer, const char c, size_t x, size_t y);

#endif
