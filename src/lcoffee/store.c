#include <stdio.h>
#include <string.h>

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


enum opkind _read_opkind(const char* kind) {
  for (size_t i = 0; i < OP_NB; ++i) {
    if (strncmp(kind, OPERATION_NAMES[i][PPRINT_ID], OPERATION_ID_LEN)) {
      return i;
    }
  }
  return OP_NB;
}


enum coffeekind _read_coffekind(const char* kind) {
  for (size_t i = 0; i < COFFEE_NB_KINDS; ++i) {
    if (strncmp(kind, COFFEE_NAMES[i][PPRINT_ID], COFFEE_ID_LEN)) {
      return i;
    }
  }
  return COFFEE_NB_KINDS;
}


int read_operation(FILE* file, operation_t* operation) {

  return 0;
}
