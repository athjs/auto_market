#include "market.h"
#include "math.h"
// returns if it's possible to buy the bumber of item
int is_possible(struct list *list, struct item *item, int number) {

  if (!list)
    return -1;
  int ref = item_ref(item);
  int cost =price_item(list, ref) * number;
  if (cost > market_balance(list))
    return 0;
  return 1;
}

// returns the maximum number purchasable
int max_possible(struct list *list, struct item *item) {
  int ref = item_ref(item);
  int cost = cost_item(list, ref);
  int balance = market_balance(list);
  return max_amount(balance, cost);
}

// Makes a purchase for the market and returns the numer of item bought
int item_purchase(struct list *list, struct item *item, int amount) {
  // if the amount is superior than the balance, we make the puchase for the
  // maximum
  if (!list)
    return -1;
  if (is_possible(list, item, amount)) {
    list_add(list, item_ref(item), amount);
    new_balance(list, -amount * cost_item(list, item_ref(item)));
    return amount;
  }
  int max = max_possible(list, item);
  list_add(list, item_ref(item), max);
  new_balance(list, -amount * cost_item(list, item_ref(item)));
  return max;
}

//updates the data base when an item is sold and returns the number of item sold
int item_sell(struct list *list, struct item *item, int amount) {
  if (!list)
    return -1;
  if (item_number(list, item_ref(item)) >= amount) {
    list_remove(item_ref(item), list);
    new_balance(list, amount * price_item(list, item_ref(item)));
    return amount;
  }
  int max = item_number(list, item_ref(item));
  new_balance(list, item_number(list, max) * price_item(list, max));
  list_add(list, item_ref(item), item_number(list, max));
  return max;
}
