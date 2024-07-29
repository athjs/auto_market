
// returns the max number you can take of a stack
int max_amount(int amount, int price) {
  int num = 0;
  while (amount > 0) {
    amount -= price;
    ++num;
  }
  return num;
}
