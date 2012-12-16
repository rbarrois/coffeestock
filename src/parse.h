#ifndef __parse_h
#define __parse_h

#include "lcoffee/stock.h"

/** Fill an operation_t* from a 12RI-like entry
 */
int fill_operation(operation_t* op, const char* entry);

/** Fill an operation_t* from an array of 12RI-like entries
 */
int fill_operation_multi(operation_t* op, const char** entries, size_t begin, size_t end);

#endif
