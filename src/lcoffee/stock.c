#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "stock.h"


/** Coffee
 */

const char* coffee_title(enum coffeekind kind, enum pprintlevel level) {
  assert(0 <= kind < COFFEE_NB_KINDS);
  assert(PPRINT_ID <= level <= PPRINT_LONG);

  return COFFEE_NAMES[kind][level];
}

const char* operation_title(enum opkind kind, enum pprintlevel level) {
  assert(0 <= kind < OP_NB);
  assert(PPRINT_ID <= level <= PPRINT_LONG);

  return OPERATION_NAMES[kind][level];
}

enum opkind read_opkind(const char* kind) {
  for (size_t i = 0; i < OP_NB; ++i) {
    if (strncmp(kind, OPERATION_NAMES[i][PPRINT_ID], OPERATION_ID_LEN) == 0) {
      return i;
    }
  }
  return OP_NB;
}


enum coffeekind read_coffeekind(const char* kind) {
  for (size_t i = 0; i < COFFEE_NB_KINDS; ++i) {
    if (strncmp(kind, COFFEE_NAMES[i][PPRINT_ID], COFFEE_ID_LEN) == 0) {
      return i;
    }
  }
  return COFFEE_NB_KINDS;
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

void operation_reset(operation_t* operation) {
  for (size_t i = 0; i < COFFEE_NB_KINDS; ++i) {
    operation->items[i] = 0;
  }
}

void operation_delete(operation_t* operation) {
  free(operation->items);
  free(operation);
}
