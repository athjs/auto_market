#include "market.h"
#include "math.h"
// returns if it's possible to buy the bumber of item
int is_possible(struct list *list, struct item *item, int number) {

  if (!list)
    return -1;
  int cost = cost_item(item) * number;
  if (cost <= market_balance(list))
    return 1;
  return 0;
}

// returns the maximum number purchasable
int max_possible(struct list *list, struct item *item) {
  int cost = cost_item(item);
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
    list_add(list, item, amount);
    new_balance(list, -amount * cost_item(item));
    return amount;
  }
  int max = max_possible(list, item);
  list_add(list, item, max);
  new_balance(list, -max * cost_item(item));
  return max;
}

// updates the data base when an item is sold and returns the number of item
// sold
int item_sell(struct list *list, struct item *item, int amount) {
  if (!list)
    return -1;
  if (is_empty(list))
    return 0;
  if (item_number(item, list) >= amount) {
    list_remove(item_ref(item), list);
    new_balance(list, amount * price_item(item));
    return amount;
  }
  int max = item_number(item, list);
  new_balance(list, item_number(item, list) * price_item(item));
  list_add(list, item, item_number(item, list));
  return max;
}
