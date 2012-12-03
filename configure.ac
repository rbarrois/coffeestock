#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
AC_INIT([coffee], [0.1.0], [xelnor_coffee@xelnor.net])

# Enable checks in Makefile.am
AM_INIT_AUTOMAKE([-Wall -Werror])

AC_CONFIG_SRCDIR([src/main.c])
AC_CONFIG_HEADERS([src/config.h])

# Checks for programs.
AC_PROG_CC
AC_PROG_RANLIB

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h string.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_INLINE
AC_TYPE_SIZE_T
AC_PROG_CC_C99

# Unittest-related code
AM_PATH_CHECK()
AM_PROG_CC_C_O

# Checks for library functions.
AC_FUNC_MALLOC

AC_CONFIG_FILES([Makefile
                 src/Makefile
                 src/lcoffee/Makefile
                 tests/Makefile])

AC_OUTPUT
