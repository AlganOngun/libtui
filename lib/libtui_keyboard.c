#include "libtui_keyboard.h"

#include <stdio.h>

libtui_keyboard libtui_keyboard_init() {
  static struct termios oldt, newt;

  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;

  newt.c_lflag &= ~(ICANON);

  tcsetattr(STDIN_FILENO, TCSANOW, &newt);

  libtui_keyboard keyboard = {.new_term = newt, .original_term = oldt};
  return keyboard;
}

LIBTUI_KEYCODE libtui_keyboard_get_key() {
  return getchar();
}

void libtui_keyboard_deinit(libtui_keyboard keyboard) {
  tcsetattr(STDIN_FILENO, TCSANOW, &keyboard.original_term);
}
