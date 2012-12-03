/** Dumps the current state of a store.
 */

#include <stdio.h>
#include <string.h>

#include "lcoffee/stock.h"
#include "lcoffee/tools.h"
#include "lcoffee/store.h"


int usage(const char* pname, int exit) {
  printf("Usage: %s FILE\n"
"\n"
"Dump the current state from file FILE.\n", pname);

  return exit;
}


int main(int argc, char** argv) {

  if (argc <= 1) {
    return usage(argv[0], 1);
  }

  if (strncmp(argv[1], "-h", 3) == 0 || strncmp(argv[1], "--help", 7) == 0) {
    return usage(argv[0], 0);
  }

  FILE* file = fopen(argv[1], "r");

  stock_t* stock = stock_init();
  operation_t* op = operation_init(OP_INVENTORY);

  while (read_operation(file, op) > 0) {
    stock_update(stock, op);
    operation_reset(op);
  }

  operation_delete(op);

  dump_stock(stock);
  stock_delete(stock);

  return 0;
}

