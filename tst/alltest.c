#include "test_market.h"
#include <stdlib.h>
#include <stdio.h>
int main() {
  test_create_list();
  test_is_empty();
  test_find();
  test_add();
  printf("\n");
  return EXIT_SUCCESS;
}
