#include <stdio.h>

#include "stock.h"
#include "store.h"


int write_operation(FILE* file, const operation_t* operation) {
  int written = 0;
  written += fprintf(file, "%s:", operation_title(operation->kind, PPRINT_ID));
  for (size_t i = 0; i < COFFEE_NB_KINDS; ++i) {
    if (operation->items[i] != 0) {
      written += fprintf(file, "%s=%d;", coffee_title(i, PPRINT_ID), operation->items[i]);
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


/** Read one operation from a file.
 * Returns 1 on success, <= 0 otherwise.
 */
int read_operation(FILE* file, operation_t* operation) {
  int reads;
  int amount = 0;
  char opkind[OPERATION_ID_LEN + 1];
  char coffeekind[COFFEE_ID_LEN + 1];
  char c;

  reads = fscanf(file, "%[A-Z]:", opkind);
  if (reads != 1) {
    return reads > 0 ? 0 : reads;
  }

  operation->kind = read_opkind(opkind);

  while ((c = fgetc(file)) != '\n') {
    ungetc(c, file);
    reads = fscanf(file, "%[A-Z]=%d;", coffeekind, &amount);
    if (reads != 2) {
      return reads > 0 ? 0 : reads;
    }
    operation_set(operation, read_coffekind(coffeekind), amount);
  }

  return 1;
}
