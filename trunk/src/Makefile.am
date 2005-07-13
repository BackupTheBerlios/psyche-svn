bin_PROGRAMS = psyche
psyche_SOURCES = psyche.c error.c utils.c windows.c workspace.c events.c \
	script.c

# set the include path found by configure
INCLUDES= $(all_includes)

# the library search path.
psyche_LDFLAGS = $(all_libraries) 

psyche_LDADD = -lpanel -lcdk -lcurses
noinst_HEADERS = events.h
