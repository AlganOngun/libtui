#include <stdio.h>

#include "../lib/libtui.h"

int main(int argc, char* argv[]) {
  buf* screen_buf = buf_create(5, 10);

  const char* init_row = "XXXXXXXXXX";
  for (int i = 0; i < 5; ++i) {
    buf_set_row(screen_buf, init_row, i);
  }

  buf_set(screen_buf, 'f', 0, 0);

  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 10; ++j) {
      const int k = screen_buf->columns * i + j;
      printf("%c", screen_buf->buf[k]);
    }
    printf("\n");
  }

  buf_free(screen_buf);

  return 0;
}
