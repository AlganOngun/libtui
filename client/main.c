#include <stdio.h>

#include "../lib/libtui.h"

int main(int argc, char* argv[]) {
  libtui_renderer* r = libtui_renderer_create(5, 10);
  buf* screen_buf = r->b;

  const char* init_row = "          ";
  for (size_t i = 0; i < 5; ++i) {
    buf_set_row(screen_buf, init_row, i);
  }

  buf_set(screen_buf, 'f', 0, 0);
  buf_set(screen_buf, 'Y', 2, 3);
  buf_set(screen_buf, 'C', 5, 4);
  buf_set(screen_buf, 'd', 8, 2);
  buf_set(screen_buf, '4', 9, 1);

  for (size_t i = 0; i < 5; ++i) {
    for (size_t j = 0; j < 10; ++j) {
      const char c = buf_get(screen_buf, j, i);
      printf("%c", c);
    }
    printf("\n");
  }

  libtui_renderer_free(r);

  return 0;
}
