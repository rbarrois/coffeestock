#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lcoffee/stock.h"
#include "lcoffee/store.h"
#include "parse.h"


int usage(const char* pname, int exit) {
    printf("Usage: %s FILE [15A [24B [...]]]\n"
           "\n"
           "Register inventory to file FILE.\n", pname);

    return exit;
}


int main(int argc, const char** argv) {
    if (argc == 1) {
        return usage(argv[0], EXIT_FAILURE);
    }

    if (strncmp(argv[1], "-h", 3) == 0 || strncmp(argv[1], "--help", 7) == 0) {
        return usage(argv[0], EXIT_SUCCESS);
    }

    if (argc == 2) {
        return usage(argv[0], EXIT_FAILURE);
    }

    operation_t* op = operation_init(OP_INVENTORY);
    int res = fill_operation_multi(op, argv, 2, argc);

    if (res != 0) {
        fprintf(stderr, "ERROR: Invalid inventory\n");
        return EXIT_FAILURE;
    }

    FILE* file = fopen(argv[1], "a");
    write_operation(file, op);
    fclose(file);
    operation_delete(op);
}

