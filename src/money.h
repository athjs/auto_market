#ifndef _MONEY_H_
#define _MONEY_H_
#include "market.h"
#include "math.h"

int is_possible(struct list *list, struct item *item, int number);

int max_possible(struct list *list, struct item *item);

int item_purchase(struct list *list, struct item *item, int amount);

int item_sell(struct list *list, struct item *item, int amount);


#endif

