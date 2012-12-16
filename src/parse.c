#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parse.h"
#include "lcoffee/stock.h"


int fill_operation(operation_t* op, const char* entry) {
    int amount = 0;
    char kind_s[COFFEE_ID_LEN + 1];

    int reads = sscanf(entry, "%d%[A-Z]", &amount, kind_s);
    if (reads != 2) {
        return reads > 0 ? 1 : reads;
    }

    enum coffeekind kind = read_coffeekind(kind_s);
    if (kind == COFFEE_NB_KINDS) {
        // Invalid coffeekind name
        fprintf(stderr, "ERROR: Invalid coffeekind %s\n", kind_s);
        return 1;
    }

    printf("%s %d %s\n", operation_title(op->kind, PPRINT_LONG),
                amount, coffee_title(kind, PPRINT_LONG));
    operation_set(op, kind, amount);

    return 0;
}


int fill_operation_multi(operation_t* op, const char** entries, size_t begin, size_t end) {
    for (size_t i = begin; i < end; ++i) {
        int res = fill_operation(op, entries[i]);
        if (res != 0) {
            return res;
        }
    }
    return 0;
}


