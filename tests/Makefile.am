TESTS = check_stock
check_PROGRAMS = $(TESTS)
check_stock_SOURCES = check_stock.c $(top_builddir)/src/lcoffee/stock.h
check_stock_CFLAGS = @CHECK_CFLAGS@
check_stock_LDADD = $(top_builddir)/src/lcoffee/libcoffee.a @CHECK_LIBS@
