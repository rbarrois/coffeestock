// va_*
#include <stdarg.h>
// fprintf
#include <stdio.h>
// bool
#include <stdbool.h>
// strncmp
#include <string.h>

#include "cli.h"

bool is_help(const char* arg) {
    return strncmp(arg, "-h", 3) == 0 || strncmp(arg, "--help", 7) == 0;
}

void error(const char* fmt, ...) {
    va_list ap;
    va_start(ap, fmt);

    fprintf(stderr, "ERROR: ");
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, "\n");

    va_end(ap);
}
