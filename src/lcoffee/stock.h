#ifndef __stock_h
#define __stock_h

#include "enums.h"

/** Operations
 */

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

enum coffeekind read_coffeekind(const char*);
enum opkind read_opkind(const char*);

#endif
