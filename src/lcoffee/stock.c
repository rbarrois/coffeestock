#include <stdlib.h>

#include "stock.h"


/** Coffee
 */

const char* coffee_title(enum coffeekind kind) {
  switch (kind) {
    case COFFEE_RISTRETTO_FORTE:
      return "Ristretto Forte";
    case COFFEE_RISTRETTO_INDIA:
      return "Ristretto Origin India";
    case COFFEE_ESPRESSO_FORTE:
      return "Espresso Forte";
    case COFFEE_ESPRESSO_LEGGERO:
      return "Espresso Leggero";
    case COFFEE_LUNGO_FORTE:
      return "Lungo Forte";
    case COFFEE_LUNGO_LEGGERO:
      return "Lungo Leggero";
    case COFFEE_DECAFFEINATO_ESPRESSO:
      return "Decaffeinato Espresso";
    case COFFEE_DECAFFEINATO_LUNGO:
      return "Decaffeinato Lungo";
    default:
      return "INVALID";
  }
}


/** Stock
 */

stock_t* stock_init() {
  stock_t* stock = malloc(sizeof(stock_t));
  if (!stock) {
    return NULL;
  }

  stock->items = calloc((size_t) COFFEE_NB_KINDS, sizeof(int));
  if (!stock->items) {
    free(stock);
    return NULL;
  }

  for (size_t i = 0; i < COFFEE_NB_KINDS; i++) {
    stock->items[i] = 0;
  }

  return stock;
}

void stock_update(stock_t* stock, const operation_t* operation) {
  for (size_t i = 0; i < COFFEE_NB_KINDS; i++) {
    switch (operation->kind) {
      case OP_INVENTORY:
        stock->items[i] = operation->items[i];
        break;
      case OP_BUY:
        stock->items[i] += operation->items[i];
        break;
      case OP_SELL:
        stock->items[i] -= operation->items[i];
        break;
    }
  }
}

void stock_delete(stock_t* stock) {
  free(stock->items);
  free(stock);
}


/** Operations
 */

operation_t* operation_init(enum opkind kind) {
  operation_t* operation = malloc(sizeof(operation_t));
  if (!operation) {
    return NULL;
  }

  operation->items = calloc((size_t) COFFEE_NB_KINDS, sizeof(int));
  if (!operation->items) {
    free(operation);
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
  free(operation->items);
  free(operation);
}
