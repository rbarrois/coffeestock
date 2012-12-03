#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stock.h"
#include "tools.h"

void dump_stock(const stock_t* stock) {
  for (size_t i = 0; i < COFFEE_NB_KINDS; i++) {
    if (stock->items[i] != 0) {
      printf("- %s: %d\n", coffee_title(i, PPRINT_LONG), stock->items[i]);
    }
  }
}


void dump_operation(const operation_t* operation) {
  printf("%s: ", operation_title(operation->kind, PPRINT_LONG));

  bool printed = false;
  for (size_t i = 0; i < COFFEE_NB_KINDS; i++) {
    if (operation->items[i] == 0) {
      continue;
    }

    if (printed) {
      printf(", ");
    }
    printf("%s => %d", coffee_title(i, PPRINT_LONG), operation->items[i]);
    printed = true;
  }
  printf("\n");
}
