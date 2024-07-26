#include "market.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct item {
  int ref;
  int number;
};

struct list {
  struct item *item;
  int size;
  int capacity;
};

struct list *create() {
  struct list *list = malloc(sizeof(struct list));
  list->item = NULL;
  list->size = 0;
  list->capacity = 0;
  return list;
}

int find(struct list *list, int ref) {
  int i = 0;
  if (list == NULL)
    return -1;
  for (; i < list->size; i++) {
    if (list->item[i].ref == ref)
      return i;
  }
  return i;
}
int is_empty(struct list *list) {
  if (list->item == NULL && list->capacity == 0)
    return 1;
  return 0;
}

// When there are new articles ref in the market or the amount of the article is
// modified

int list_add(struct list *list, int ref, int number) {
  if (!list)
    return -1;
  // case i the item is in the array
  if (is_empty(list)) {
    list->item = malloc(sizeof(struct item));
    list->item[0].number = number;
    list->item[0].ref = ref;
    list->capacity++;
    list->size++;
    return 1;
  }
  int here = find(list, ref);
  if (here < list->capacity) {
    list->item[here].number += number;
  }
  // item isn't in the database
  else {
    // case the data base is big enough
    if (list->size < list->capacity) {
      list->item[here].ref = ref;
      list->item[here].number = number;
    }
    // case the database isn't big enough
    list->item = realloc(list->item, 2 * list->capacity * sizeof(struct item));
    list->capacity *= 2;
    list->item[here].ref = ref;
    list->item[here].number = number;
  }
  list->size++;
  return 1;
}

void shift__left(struct item *item, int size, int begin) {
  for (int i = begin; i < size - 1; i++) {
    item[i] = item[i + 1];
  }
}
// when the market deletes an article ref
int list_remove(int ref, struct list *list) {
  if (!list)
    return -1;
  if (is_empty(list))
    return -2;
  int here = find(list, ref);
  if (here == list->size)
    return 0;
  else {
    if (list->size == list->capacity / 2) {
      list->item = realloc(list->item, list->size * sizeof(struct item));
      list->capacity = list->capacity / 2;
      shift__left(list->item, list->size, here);
    } else {
      shift__left(list->item, list->size, here);
    }
  }
  list->size--;
  return 1;
}

// modifies the ref of an item (later we will use void * to change the )
int list_modify(struct list *list, int ref, int new_ref) {
  if (!list)
    return -1;
  if (is_empty(list))
    return -2;
  int here = find(list, ref);
  if (here == list->size)
    return 0;
  list->item[here].ref = new_ref;
  return 1;
}

int list_size(struct list *list) { return list->size; }

int list_capacity(struct list *list) { return list->capacity; }
// Prints items in the list
int item_number(struct list *list, int ref) {
  int here = find(list, ref);
  if (here == list->size)
    return -1;
  return list->item[here].number;
}
void list_print(struct list *list) {
  for (int i = 0; i < list->size; ++i) {
    printf("%3d %3d \n ", list->item[i].ref, list->item[i].number);
  }
}
// freed the list
void list_free(struct list *list) {
  free(list->item);
  free(list);
}
