#ifndef _MARKET_H_
#define _MARKET_H_
struct set;

struct item;

struct list;

struct list *create(void);

void shift__left(struct item *item, int size, int begin);

int find(struct list *list, int ref);

int is_empty(struct list *list);

int list_add(struct list *list, int ref, int number);

int list_remove(int ref, struct list *list);

int list_modify(struct list *list, int ref, int new_ref);

int list_capacity(struct list *list);

int list_size(struct list *list);

int item_number(struct list *list, int ref);

void list_print(struct list *list);

void list_free(struct list *list);

#endif // !_MARKET_H_
