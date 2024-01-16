#include "libtui_term_control.h"

#include <stdio.h>
#include <stdlib.h>

void libtui_hide_cursor(void) {
  printf("\e[?25l");
  fflush(stdout);
}

void libtui_show_cursor(void) {
  printf("\e[?25h");
  fflush(stdout);
}

void libtui_true_clear(void) {
  system("clear");
}
