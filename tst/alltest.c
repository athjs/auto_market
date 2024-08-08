#include "test_market.h"
#include "test_money.h"
#include <stdio.h>
#include <stdlib.h>
int main() {
  test_create_list();
  test_is_empty();
  test_find();
  test_add();
  test_remove();
  test_modify();
  test_balance_update();
  test_is_possible();
  test_max_possible();
  test_item_purchase();
  test_item_sell();
  printf("\n");
  return EXIT_SUCCESS;
}
