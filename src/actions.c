// EXIT_*
#include <stdlib.h>
// printf, fopen, fclose
#include <stdio.h>

// write_operation
#include "lcoffee/store.h"
// operation_init, operation_delete
#include "lcoffee/stock.h"

// is_help, error
#include "cli.h"

#include "actions.h"

/** Buy
 */

int usage_buy(const char* pname, int exit) {
    printf("Usage: %s FILE buy [15RR [20RI [...]]]\n"
           "\n"
           "Register a 'buy' order of 15RR, 20RI, ...\n", pname);
    return exit;
}

int buy(const char* pname, const char* fname, int argc, const char** argv) {
    if (argc == 0) {
        error("The 'buy' action requires at least one coffee amount + kind\n");
        return usage_buy(pname, EXIT_FAILURE);
    } else if (is_help(argv[0])) {
        return usage_buy(pname, EXIT_SUCCESS);
    }

    operation_t* op = operation_init(OP_BUY);
    int res = fill_operation_multi(op, argv, 0, argc);

    if (res != 0) {
        error("Invalid buy order");
        return EXIT_FAILURE;
    }

    FILE* file = fopen(fname, "a");
    write_operation(file, op);
    fclose(file);
    operation_delete(op);

    return EXIT_SUCCESS;
}

int sell(const char* pname, const char* fname, int argc, const char** argv) {
    return EXIT_SUCCESS;
}

int inventory(const char* pname, const char* fname, int argc, const char** argv) {
    return EXIT_SUCCESS;
}

int state(const char* pname, const char* fname, int argc, const char** argv) {
    return EXIT_SUCCESS;
}

int history(const char* pname, const char* fname, int argc, const char** argv) {
    return EXIT_SUCCESS;
}
