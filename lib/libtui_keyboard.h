#ifndef LIBTUI_KEYBOARD_H
#define LIBTUI_KEYBOARD_H

#include <stdbool.h>

/*
 * Complete enum of keycodes with the referring ascii codes.
 */
enum LIBTUI_KEYCODE {
	KEY_BS = 8, // Backspace
	KEY_TAB = 9, // Horizontal Tab
	KEY_ESC = 27, // Escape

	KEY_SPACE = 32,
	KEY_SINGLE_QUOTE = 39, // '
	KEY_ASTERISK = 42, // *
	KEY_PLUS = 43, // +
	KEY_COMMA = 44, // ,
	KEY_MINUS = 45, // -
	KEY_PERIOD = 46, // .
	KEY_SLASH = 47, // /
	KEY_0 = 48,
	KEY_1 = 49,
	KEY_2 = 50,
	KEY_3 = 51,
	KEY_4 = 52,
	KEY_5 = 53,
	KEY_6 = 54,
	KEY_7 = 55,
	KEY_8 = 56,
	KEY_9 = 57,
	KEY_SEMICOLON = 59, // ;
	KEY_EQUAL = 61, // =
	KEY_OPEN_BRACKET = 91, // [
	KEY_BACKSLASH = 92, /* \ */
	KEY_CLOSE_BRACKET = 93, // ]
	KEY_BACKQUOTE = 96, // `
	KEY_A = 97,
	KEY_B = 98,
	KEY_C = 99,
	KEY_D = 100,
	KEY_E = 101,
	KEY_F = 102,
	KEY_G = 103,
	KEY_H = 104,
	KEY_I = 105,
	KEY_J = 106,
	KEY_K = 107,
	KEY_L = 108,
	KEY_M = 109,
	KEY_N = 110,
	KEY_O = 111,
	KEY_P = 112,
	KEY_Q = 113,
	KEY_R = 114,
	KEY_S = 115,
	KEY_T = 116,
	KEY_U = 117,
	KEY_V = 118,
	KEY_W = 119,
	KEY_X = 120,
	KEY_Y = 121,
	KEY_Z = 122,
	KEY_DEL = 127, // Delete
};

/*
 * Returns true if a key is pressed
 */
bool libtui_keyboard_is_kb_hit(void);

/*
 * Returns the key pressed
 */
enum LIBTUI_KEYCODE libtui_keyboard_get_key(void);

#endif
