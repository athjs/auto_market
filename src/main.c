#include "market.h"
#include <stdlib.h>

int main(int argc, char **argv) {
  int money;
  if (argc > 0)
    money = atoi(argv[0]);
  else
    money = 0;
  struct list *list = create();
  list_free(list);
  return EXIT_SUCCESS;
}
