#ifndef __stock_h
#define __stock_h

enum opkind {
  OP_INVENTORY,
  OP_BUY,
  OP_SELL
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
  int[COFFEE_NB_KINDS] items;
} operation_t;

typedef struct _stock {
  int[COFFEE_NB_KINDS] items;
} stock_t;


stock_t* stock_init();
void stock_update(stock_t* stock, operation_t* operation);
void stock_delete(stock_t*);


operation_t* operation_init(enum opkind kind);
void operation_set(operation_t* operation, enum coffeekind coffee, int amount);
void operation_delete(operation_t*);


#endif
