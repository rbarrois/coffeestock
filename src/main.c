#include <stdio.h>

#include "lcoffee/stock.h"
#include "lcoffee/tools.h"
#include "lcoffee/store.h"

int main() {
  stock_t* stock = stock_init();

  printf("History:\n");
  printf("========\n");
  operation_t* op = operation_init(OP_INVENTORY);
  operation_set(op, COFFEE_RISTRETTO_FORTE, 1);
  operation_set(op, COFFEE_LUNGO_FORTE, 4);
  dump_operation(op);

  stock_update(stock, op);
  operation_delete(op);

  operation_t* op2 = operation_init(OP_SELL);
  operation_set(op2, COFFEE_LUNGO_FORTE, 2);
  dump_operation(op2);

  stock_update(stock, op2);
  operation_delete(op2);

  printf("\n");
  printf("Stock:\n");
  printf("======\n");
  dump_stock(stock);

  FILE* f = fopen("stock.out", "w");
  write_stock(f, stock);
  fclose(f);

  stock_delete(stock);

  return 0;
}
