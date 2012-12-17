// printf
#include <stdio.h>
// EXIT_*
#include <stdlib.h>
// strncmp
#include <string.h>

// is_help, error
#include "cli.h"

// All actions
#include "actions.h"


int usage(const char* pname, int exit) {
    printf("Usage: %s FILE <buy|sell|inventory|state|history> ...\n"
           "\n"
           "Perform the chosen action on file FILE.\n", pname);
    return exit;
}


int main(int argc, const char** argv) {
    const char* pname = argv[0];

    if (argc >= 2 && is_help(argv[1])) {
        return usage(pname, EXIT_SUCCESS);
    } else if (argc >= 3 && is_help(argv[2])) {
        return usage(pname, EXIT_SUCCESS);
    } else if (argc <= 2) {
        error("Not enough arguments");
        return usage(pname, EXIT_FAILURE);
    }

    const char* fname = argv[1];
    const char* action = argv[2];

    int sub_argc = argc - 3;
    const char** sub_argv = argv + 3;

    if (strncmp(action, "buy", 4) == 0) {
        return buy(pname, fname, sub_argc, sub_argv);
    } else if (strncmp(action, "sell", 5) == 0) {
        return sell(pname, fname, sub_argc, sub_argv);
    } else if (strncmp(action, "inventory", 10) == 0) {
        return inventory(pname, fname, sub_argc, sub_argv);
    } else if (strncmp(action, "state", 6) == 0) {
        return inventory(pname, fname, sub_argc, sub_argv);
    } else if (strncmp(action, "history", 8) == 0) {
        return history(pname, fname, sub_argc, sub_argv);
    } else {
        error("Unknown action %s", action);
        return usage(argv[0], EXIT_FAILURE);
    }
}
