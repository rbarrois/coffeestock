#include <stdio.h>

#include "stock.h"
#include "store.h"


int write_operation(FILE* file, const operation_t* operation) {
  int written = 0;
  written += fprintf(file, "%s:", operation_title(operation->kind, false));
  for (size_t i = 0; i < COFFEE_NB_KINDS; ++i) {
    if (operation->items[i] != 0) {
      written += fprintf(file, "%s=%d;", coffee_title(i, true), operation->items[i]);
    }
  }
  written += fprintf(file, "\n");
  return written;
}

int write_stock(FILE* file, const stock_t* stock) {
  operation_t* op = operation_init(OP_INVENTORY);
  for (size_t i = 0; i < COFFEE_NB_KINDS; ++i) {
    operation_set(op, i, stock->items[i]);
  }

  int written = write_operation(file, op);

  operation_delete(op);

  return written;
}

int read_operation(FILE* file, operation_t* operation) {
  return 0;
}
