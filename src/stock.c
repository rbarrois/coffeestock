#include "stock.h"


/* Stock
 */


stock_t* stock_init() {
  stock = malloc(sizeof(stock_t));
  if (!stock_t) {
    return NULL;
  }

  for (i = 0; i < COFFEE_NB_KINDS; i++) {
    stock->items[i] = 0;
  }

  return stock;
}

void stock_update(stock_t* stock, operation_t* operation) {
  for (size_t = 0; i < COFFEE_NB_KINDS; i++) {
    switch (operation->kind) {
      case OP_INVENTORY:
        stock->items[i] = operation[i];
        break;
      case OP_BUY:
        stock->items[i] += operation[i];
        break;
      case OP_SELL:
        stock->items[i] -= operation[i];
        break;
    }
  }
}

void stock_delete(stock_t* stock) {
  free(stock);
}


/** Operations
 */

operation_t* operation_init(enum opkind kind) {
  operation = malloc(sizeof(operation_t));
  if (!operation) {
    return NULL;
  }

  operation->kind = kind;
  for (size_t i = 0; i < COFFEE_NB_KINDS; i++) {
    operation->items[i] = 0;
  }

  return operation;
}

void operation_set(operation_t* operation, enum coffeekind coffee, int amount) {
  operation->items[coffee] = amount;
}

void operation_delete(operation_t* operation) {
  free(operation);
}
