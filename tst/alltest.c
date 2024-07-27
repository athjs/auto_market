#include "test_market.h"
#include <stdio.h>
#include <stdlib.h>
int main() {
  test_create_list();
  test_is_empty();
  test_find();
  test_add();
  test_remove();
  test_modify();
  printf("\n");
  return EXIT_SUCCESS;
}
