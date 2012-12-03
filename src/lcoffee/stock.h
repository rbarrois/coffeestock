#ifndef __stock_h
#define __stock_h

#include <stdbool.h>

/** Operations
 */

enum opkind {
  OP_INVENTORY,
  OP_BUY,
  OP_SELL,

  OP_NB  // For lookups
};

enum coffeekind {
  COFFEE_RISTRETTO_FORTE,
  COFFEE_RISTRETTO_INDIA,
  COFFEE_ESPRESSO_FORTE,
  COFFEE_ESPRESSO_LEGGERO,
  COFFEE_LUNGO_FORTE,
  COFFEE_LUNGO_LEGGERO,
  COFFEE_DECAFFEINATO_ESPRESSO,
  COFFEE_DECAFFEINATO_LUNGO,

  COFFEE_NB_KINDS  // For lookups
};

typedef struct _operation {
  enum opkind kind;
  int* items;
} operation_t;

operation_t* operation_init(enum opkind kind);
void operation_set(operation_t* operation, enum coffeekind coffee, int amount);
void operation_delete(operation_t*);


/** Stock
 */

typedef struct _stock {
  int* items;
} stock_t;

stock_t* stock_init();
void stock_update(stock_t* stock, const operation_t* operation);
void stock_delete(stock_t*);


/** Pretty-print
 */

enum pprintlevel {
  PPRINT_ID,
  PPRINT_SHORT,
  PPRINT_LONG,
};

const char* coffee_title(enum coffeekind kind, enum pprintlevel level);
const char* operation_title(enum opkind kind, enum pprintlevel level);




#endif
