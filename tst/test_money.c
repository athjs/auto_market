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

void test_max_possible() {
  struct list *list = create();
  struct item *item = product(1, 11, 20, 1);
  assert(max_possible(list, item) == 0);
  new_balance(list, 100);
  assert(max_possible(list, item) == 9);
  list_add(list, 1, 9);
  new_balance(list, -99);
  assert(max_possible(list, item) == 0);
  list_free(list);
  printf("*");
}

void test_item_purchase() {
  struct list *list = create();
  struct item *item = product(1, 10, 20, 1);
  new_balance(list, 100);
  item_purchase(list, item, 10);
  assert(item_number(item,list) == 10);
  assert(market_balance(list) == 0);
  new_balance(list, 14);
  item_purchase(list, item, 2);
  assert(item_number(item,list) == 11);
  assert(market_balance(list) == 4);
  list_free(list);
  printf("*");
}
