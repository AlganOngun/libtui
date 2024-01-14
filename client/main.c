#include <stdio.h>
#include <termios.h>
#include <unistd.h>

#include "../lib/libtui.h"

int main(int argc, char* argv[]) {
  int c;
  static struct termios oldt, newt;

  /*tcgetattr gets the parameters of the current terminal
  STDIN_FILENO will tell tcgetattr that it should write the settings
  of stdin to oldt*/
  tcgetattr(STDIN_FILENO, &oldt);
  /*now the settings will be copied*/
  newt = oldt;

  /*ICANON normally takes care that one line at a time will be processed
  that means it will return if it sees a "\n" or an EOF or an EOL*/
  newt.c_lflag &= ~(ICANON);

  /*Those new settings will be set to STDIN
  TCSANOW tells tcsetattr to change attributes immediately. */
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);

  /*This is your part:
  I choose 'e' to end input. Notice that EOF is also turned off
  in the non-canonical mode*/
  libtui_renderer* r = libtui_renderer_create(10, 5);

  libtui_draw_clear_with(r, '_');

  size_t x = 0;
  size_t y = 0;
  while (1) {
    libtui_draw_single_char(r, 'X', x, y);
    libtui_renderer_render(r);
    char c = getchar();
    switch (c) {
      case 'd': {
        ++x;
        if (x >= r->columns) {
          fprintf(stderr, "ERROR!!");
          exit(1);
        }
      } break;
      case 'a': --x; break;
      case 'w': --y; break;
      case 's': ++y; break;
    }
  }

  libtui_renderer_free(r);

  /*restore the old settings*/
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

  return 0;
}
