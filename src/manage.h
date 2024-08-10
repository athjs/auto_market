#ifndef _MANAGE_H_
#define _MANAGE_H_

#include "market.h"
#include "money.h"

#define MINIMUM 15

struct list *broken_item(struct list *list, struct item *item, int number);

int is_enough(struct list *list, struct item *item);

struct list *prepare_order(struct list *list, struct item *item);

struct list *make_order(struct list *list, struct list *order);

#endif
