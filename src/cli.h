#ifndef __cli_h
#define __cli_h

// bool
#include <stdbool.h>

// vararg
#include <stdarg.h>

/** Check whether an argument is a "help" marker.
 */
bool is_help(const char* arg);

/** Print an error message on stderr.
 * This is a variadic function.
 *
 * Ex:
 * error("Invalid action %s\n", action);
 */
void error(const char* fmt, ...);

#endif
