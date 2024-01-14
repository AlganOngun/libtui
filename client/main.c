#include <stdio.h>

#include "../lib/libtui.h"

int main(int argc, char* argv[]) {
  buf* screen_buf = buf_create(5, 10);

  const char* init_row = "XXXXXXXXXX";
  for (size_t i = 0; i < 5; ++i) {
    buf_set_row(screen_buf, init_row, i);
  }

  buf_set(screen_buf, 'f', 0, 0);

  for (size_t i = 0; i < 5; ++i) {
    for (size_t j = 0; j < 10; ++j) {
      const char c = buf_get(screen_buf, j, i);
      printf("%c", c);
    }
    printf("\n");
  }

  buf_free(screen_buf);

  return 0;
}
