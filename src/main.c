#include <stdio.h>
#include <stdlib.h>

#include "lcoffee/stock.h"

int main(int argc, char** argv) {
  stock_t* stock = stock_init();
  operation_t* op = operation_init(OP_INVENTORY);
  operation_set(op, COFFEE_RISTRETTO_FORTE, 1);
  operation_set(op, COFFEE_LUNGO_FORTE, 4);
  stock_update(stock, op);
  operation_delete(op);

  operation_t* op2 = operation_init(OP_SELL);
  operation_set(op2, COFFEE_LUNGO_FORTE, 2);
  stock_update(stock, op2);
  operation_delete(op2);

  for (size_t i = 0; i < COFFEE_NB_KINDS; i++) {
    if (stock->items[i] != 0) {
      printf("- %s: %d\n", coffee_title(i), stock->items[i]);
    }
  }

  stock_delete(stock);

  return 0;
}
