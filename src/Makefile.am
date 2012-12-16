AM_CFLAGS=-ggdb -W -Wall -Wno-unused-parameter -Wno-unused-function -Wno-unused-label -Wpointer-arith -Wformat -Wimplicit -Wreturn-type -Wsign-compare -Wno-multichar -Winit-self -Wextra -Werror

bin_PROGRAMS = main main2 history state buy sell inventory
#main_SOURCES = main.c
main_LDADD = lcoffee/libcoffee.a

#main2_SOURCES = main2.c
main2_LDADD = lcoffee/libcoffee.a

#history_SOURCES = history.c
history_LDADD = lcoffee/libcoffee.a

#state_SOURCES = state.c
state_LDADD = lcoffee/libcoffee.a

buy_SOURCES = buy.c parse.h parse.c
buy_LDADD = lcoffee/libcoffee.a

sell_SOURCES = sell.c parse.h parse.c
sell_LDADD = lcoffee/libcoffee.a

inventory_SOURCES = inventory.c parse.h parse.c
inventory_LDADD = lcoffee/libcoffee.a

SUBDIRS = lcoffee
