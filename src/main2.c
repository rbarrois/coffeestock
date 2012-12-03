#include <stdio.h>

#include "lcoffee/stock.h"
#include "lcoffee/tools.h"
#include "lcoffee/store.h"

int main() {
  stock_t* stock = stock_init();
  FILE* file = fopen("stock.out", "r");

  operation_t* op = operation_init(OP_INVENTORY);

  while (read_operation(file, op) > 0) {
    dump_operation(op);
    stock_update(stock, op);
    operation_reset(op);
  }

  dump_stock(stock);

  operation_delete(op);
  stock_delete(stock);

  return 0;
}
