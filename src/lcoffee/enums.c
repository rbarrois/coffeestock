#include "enums.h"

const char* COFFEE_NAMES[][COFFEE_NB_KINDS] = {
  // ID, Short, Long
  {"RF", "Rist F", "Ristretto Forte"},
  {"RI", "Rist I", "Ristretto Origin India"},
  {"EF", "Espr F", "Espresso Forte"},
  {"EL", "Espr L", "Espresso Leggero"},
  {"LF", "Lngo F", "Lungo Forte"},
  {"LL", "Lngo L", "Lungo Leggero"},
  {"DE", "Deca E", "Decaffeinato Espresso"},
  {"DL", "Deca L", "Decaffeinato Lungo"},
};

const char* OPERATION_NAMES[][OP_NB] = {
  // ID, Short, Long
  {"INV", "=", "Inv"},
  {"BUY", "+", "Buy"},
  {"SEL", "-", "Sell"},
};
