#ifndef __enum_h
#define __enum_h

/** Coffee
 */

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

extern const char* COFFEE_NAMES[][COFFEE_NB_KINDS];

// Length of Coffee identifiers
#define COFFEE_ID_LEN 2


/** Operations
 */

enum opkind {
  OP_INVENTORY,
  OP_BUY,
  OP_SELL,

  OP_NB  // For lookups
};

extern const char* OPERATION_NAMES[][OP_NB];

// Length of operation identifiers
#define OPERATION_ID_LEN 3

#endif
