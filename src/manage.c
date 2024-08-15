#include "manage.h"
#include "market.h"
#include <stdlib.h>

struct list *broken_item(struct list *list, struct item *item, int number) {
  list_add(list, item, -number);
  return list;
}

int is_enough(struct list *list, struct item *item) {
  if (item_number(item, list) > MINIMUM)
    return 1;
  else
    return 0;
}

struct list *item_ood(struct list *list, struct item *item, int number) {
  // if (is_item_ood(item, )) when date will be implemented
  list_add(list, item, number);
  return list;
}

struct list *prepare_order(struct list *list, struct item *item) {
  struct list *order = create();
  int length = list_size(list);
  struct item *current_item;
  for (int i = 0; i < length; ++i) {
    current_item = access_item(list, i);
    if (item_number(current_item, list) < MINIMUM)
      list_add(order, current_item, item_number(current_item, list) - MINIMUM);
  }
  return order;
}

struct list *make_order(struct list *list, struct list *order) {
  int length = list_size(order);
  int amount;
  int *references = got_references(order);
  if (references == NULL)
    return NULL;
  struct item *item;
  for (int i = 0; i < length; ++i) {

    item = access_item(order, references[i]);
    item_purchase(list, item, MINIMUM - item_number(item, order));
  }
  return list;
}


