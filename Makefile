# Makefile

CC = gcc
LIB = liblinkedlist.a
AR = ar
#CFLAGS = -D LINKEDLIST_TEST

OBJS = linkedlist.o

all: $(LIB)

$(LIB): $(OBJS)
	$(AR) cru $(LIB) $(OBJS)

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -rf *.o *.a
