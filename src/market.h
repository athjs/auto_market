#ifndef _MARKET_H_

struct set;

struct list;

#define INVALID_REF -1

void shif_left(struct item *item, int size, int begin);

struct list *create(void);

int find(struct list *list, int ref);

int is_empty(struct list *list);

int list_add(struct list *list, int ref, int number);

int list_remove(int ref, struct list *list) ;

int list_modify(struct list *list, int ref, int new_ref);

void list_print(struct list *list);

void list_free(struct list *list); 

#endif // !_MARKET_H_
