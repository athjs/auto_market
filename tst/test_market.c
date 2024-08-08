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
  struct item *item = product(3, 1, 2, 0);
  assert(find(list, 0) == 0);
  list_add(list, item, 1);
  struct item *item14 = product(14, 1, 2, 0);
  assert(find(list, 14) == 1);
  list_add(list, item14, 14);
  struct item *item2 = product(2, 1, 2, 0);
  list_add(list, item2, 2);
  assert(find(list, 14) == 1);
  printf("*");
  list_free(list);
}

struct list *create_list_nempty() {
  struct list *list = create();

  struct item *item = product(1, 1, 2, 0);
  struct item *item1 = product(2, 1, 2, 0);
  struct item *item2 = product(3, 1, 2, 0);
  list_add(list, item, 1);
  list_add(list, item1, 2);
  list_add(list, item2, 3);
  return list;
}

void test_add() {
  struct list *list = create_list_nempty();
  assert(find(list, 1) == 0);
  struct item *item = access_item(list, find(list, 1));
  assert(item_number(item, list) == 1);
  list_add(list, item, 15);
  assert(item_number(item, list) == 16);
  printf("*");
  list_free(list);
}

void test_remove() {
  struct list *list = create();
  assert(list_remove(0, list) == -2);
  list_free(list);
  struct list *liste = create_list_nempty();
  assert(list_remove(14, list) == 0);
  assert(list_remove(2, liste) == 1);
  assert(list_size(liste) == 2);
  assert(list_capacity(liste) == 4);
  list_remove(2, liste);
  list_remove(1, liste);
  assert(list_size(liste) == 1);
  assert(list_capacity(liste) == 2);
  list_remove(0, liste);
  assert(list_size(liste) == 1);
  assert(list_capacity(list) ==2);
  list_free(liste);
  printf("*");
}

void test_modify() {
  struct list *list = create();
  assert(list_modify(list, 0, 1) == -2);
  list_free(list);
  struct list *liste = create_list_nempty();
  assert(list_modify(liste, 14, 2) == 0);
  assert(list_modify(liste, 1, 14) == 1);
  list_modify(liste, 1, 14);
  assert(find(liste, 14) == 0);
  list_free(liste);
  printf("*");
}

void test_balance_update() {
  struct list *list = create();
  assert(market_balance(list) == 0);
  new_balance(list, 100);
  assert(market_balance(list) == 100);
  new_balance(list, -100);
  assert(market_balance(list) == 0);
  new_balance(list, -1);
  assert(market_balance(list) == 0);
  list_free(list);
  printf("*");
}
