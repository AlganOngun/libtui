#include "libtui_error.h"

#include <stdio.h>
#include <stdlib.h>

libtui_error libtui_error_create(const char* msg) {
  return (libtui_error) {.msg = msg};
}

void libtui_error_throw(const libtui_error e) {
  fprintf(stderr, "%s", e.msg);
  exit(EXIT_FAILURE);
}

void libtui_error_throw_condition(bool condition, const libtui_error e) {
  if (condition == false) return;

  libtui_error_throw(e);
}
