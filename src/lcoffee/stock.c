#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stock.h"


/** Coffee
 */

const char* coffee_title(enum coffeekind kind, enum pprintlevel level) {
  assert(0 <= kind < COFFEE_NB_KINDS);
  assert(PPRINT_ID <= level <= PPRINT_LONG);

  const char* titles[][COFFEE_NB_KINDS] = {
    {"RF", "Rist F", "Ristretto Forte"},
    {"RI", "Rist I", "Ristretto Origin India"},
    {"EF", "Espr F", "Espresso Forte"},
    {"EL", "Espr L", "Espresso Leggero"},
    {"LF", "Lngo F", "Lungo Forte"},
    {"LL", "Lngo L", "Lungo Leggero"},
    {"DE", "Deca E", "Decaffeinato Espresso"},
    {"DL", "Deca L", "Decaffeinato Lungo"},
  };

  return titles[kind][level];
}

const char* operation_title(enum opkind kind, enum pprintlevel level) {
  assert(0 <= kind < OP_NB);
  assert(PPRINT_ID <= level <= PPRINT_LONG);

  const char* titles[][OP_NB] = {
    {"INV", "=", "Inv"},
    {"BUY", "+", "Buy"},
    {"SEL", "-", "Sell"},
  };

  return titles[kind][level];
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
