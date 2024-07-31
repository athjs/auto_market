#include "../src/money.h"
#include <assert.h>
#include <printf.h>

void test_is_possible() {
  struct list *list = create();
  new_balance(list, 10);
  struct item *item = product(1, 11, 15, 1);
  assert(is_possible(list, item, 1) == 0);
  new_balance(list, 1);
  assert(is_possible(list, item, 1) == 1);
  list_add(list, 0, 1);
  list_free(list);
  printf("*");
}
