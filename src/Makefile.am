AM_CFLAGS=-ggdb -W -Wall -Wno-unused-parameter -Wno-unused-function -Wno-unused-label -Wpointer-arith -Wformat -Wimplicit -Wreturn-type -Wsign-compare -Wno-multichar -Winit-self -Wextra -Werror

bin_PROGRAMS = main main2 history state
main_SOURCES = main.c
main_LDADD = lcoffee/libcoffee.a

main2_SOURCES = main2.c
main2_LDADD = lcoffee/libcoffee.a

history_SOURCES = history.c
history_LDADD = lcoffee/libcoffee.a

state_SOURCES = state.c
state_LDADD = lcoffee/libcoffee.a

SUBDIRS = lcoffee
