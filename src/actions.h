#ifndef __actions_h
#define __actions_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lcoffee/stock.h"
#include "lcoffee/store.h"
#include "parse.h"

int buy(const char* pname, const char* fname, int argc, const char** argv);
int sell(const char* pname, const char* fname, int argc, const char** argv);
int inventory(const char* pname, const char* fname, int argc, const char** argv);
int state(const char* pname, const char* fname, int argc, const char** argv);
int history(const char* pname, const char* fname, int argc, const char** argv);

#endif
