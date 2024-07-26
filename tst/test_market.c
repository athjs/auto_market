#include "test_market.h"
#include "../src/market.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void test_create_list() {
  struct list *list = create();
  int size = 0, capacity = 0;
  assert(capacity == list_capacity(list));
  assert(size == list_size(list));
  printf("*");
  list_free(list);
}

void test_is_empty() {
  struct list *list = create();
  assert(is_empty(list) == 1);
  printf("*");
  list_free(list);
}

void test_find() {
  struct list *list = create();
  assert(find(list, 0) == 0);
  list_add(list, 1, 1);
  assert(find(list, 14) == 1);
  list_add(list, 14, 14);
  list_add(list, 2, 2);
  assert(find(list, 14) == 1);
  printf("*");
  list_free(list);
}

struct list *create_list_nempty() {
  struct list *list = create();
  list_add(list, 0, 0);
  list_add(list, 1, 1);
  list_add(list, 2, 2);
  return list;
}

void test_add() {
  struct list *list = create_list_nempty();
  assert(find(list, 1) == 1);
  assert(item_number(list, 1) == 1);
  list_add(list, 1, 15);
  assert(item_number(list, 1) == 16);
  printf("*");
  list_free(list);
}
