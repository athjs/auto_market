#ifndef _MARKET_H_
#define _MARKET_H_

struct item;

struct list;

struct date;

struct list *create(void);

struct item *product(int ref, int cost, int price, int number);

struct item *access_item(struct list *list, int ref);

void shift__left(struct item *item, int size, int begin);

int find(struct list *list, int ref);

int is_empty(struct list *list);

int list_add(struct list *list, struct item *item, int number);

int list_remove(int ref, struct list *list);

int list_modify(struct list *list, int ref, int new_ref);

int list_capacity(struct list *list);

int list_size(struct list *list);

int item_number(struct item *item, struct list *list);

void list_print(struct list *list);

void list_free(struct list *list);

int cost_item(struct item *item);

int price_item(struct item *item);

int market_balance(struct list *list);

int item_ref(struct item *item);

int new_balance(struct list *list, int amount);

int item_purchase(struct list *list, struct item *item, int amount);

int item_sell(struct list *list, struct item *item, int amount);

int *got_references(struct list *list);

int is_item_ood(struct item *item, struct date *date);

#endif // !_MARKET_H_
