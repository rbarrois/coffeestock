#include "stock.h"

void main() {
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

  int total = 0;
  for (i = 0; i < COFFEE_NB_KINDS; i++) {
    total += stock->items[i];
  }

  printf("Total stock: %d", total);

  stock_delete(stock);
}
