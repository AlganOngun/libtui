#ifndef LIBTUI_KEYBOARD_H
#define LIBTUI_KEYBOARD_H
#include <stdbool.h>
#include <termios.h>
#include <unistd.h>

typedef enum {
  KEY_BS = 8,    // Backspace
  KEY_TAB = 9,   // Horizontal Tab
  KEY_ESC = 27,  // Escape

  KEY_SPACE = 32,
  KEY_EXCLAMATION = 33,   // !
  KEY_DOUBLE_QUOTE = 34,  // "
  KEY_HASH = 35,          // #
  KEY_DOLLAR = 36,        // $
  KEY_PERCENT = 37,       // %
  KEY_AMPERSAND = 38,     // &
  KEY_SINGLE_QUOTE = 39,  // '
  KEY_OPEN_PAREN = 40,    // (
  KEY_CLOSE_PAREN = 41,   // )
  KEY_ASTERISK = 42,      // *
  KEY_PLUS = 43,          // +
  KEY_COMMA = 44,         // ,
  KEY_MINUS = 45,         // -
  KEY_PERIOD = 46,        // .
  KEY_SLASH = 47,         // /
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
  KEY_COLON = 58,          // :
  KEY_SEMICOLON = 59,      // ;
  KEY_LESS_THAN = 60,      // <
  KEY_EQUAL = 61,          // =
  KEY_GREATER_THAN = 62,   // >
  KEY_QUESTION = 63,       // ?
  KEY_AT = 64,             // @
  KEY_OPEN_BRACKET = 91,   // [
  KEY_BACKSLASH = 92,      /* \ */
  KEY_CLOSE_BRACKET = 93,  // ]
  KEY_CARET = 94,          // ^
  KEY_UNDERSCORE = 95,     // _
  KEY_BACKQUOTE = 96,      // `
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
  KEY_OPEN_BRACE = 123,   // {
  KEY_PIPE = 124,         // |
  KEY_CLOSE_BRACE = 125,  // }
  KEY_TILDE = 126,        // ~
  KEY_DEL = 127,          // Delete
} LIBTUI_KEYCODE;

// Simple: A struct that is used by keyboard input functions.
// ===========================================================================.
// Detailed: The struct used to store termios fields related to keyboard input.
typedef struct {
  struct termios original_term;
  struct termios new_term;
} libtui_keyboard;

// Simple:
// initializes all the things related to keyboard input and returns it.
// ====================================================================.
// Detailed:
// Sets the termios using tcgetattr STDIN_FILENO.
// Sets terminal flag ICANON.
// Sets the stdin with the new settings (libtui_keyboard.new_term)
libtui_keyboard libtui_keyboard_init();

// Returns the key pressed
LIBTUI_KEYCODE libtui_keyboard_get_key();

// Simple:
// Always run this function after your input work.
// Not running this function might cause undefined behaviour.
// ==========================================================.
// Detailed:
// Restores the old termios setting
void libtui_keyboard_deinit(libtui_keyboard keyboard);

#endif
