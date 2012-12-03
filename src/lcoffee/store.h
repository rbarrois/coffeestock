#ifndef __store_h
#define __store_h

#include <stdio.h>

#include "stock.h"


int write_operation(FILE* file, const operation_t* operation);
int write_stock(FILE* file, const stock_t* stock);
int read_operation(FILE* file, operation_t* operation);


#endif
