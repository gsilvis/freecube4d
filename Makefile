# Makefile.
#

CC= gcc
CFLAGS= -Wall -std=gnu99
DEBUG= -g
O= bin
ODEBUG= bin/debug

OBJS = $(O)/main.o $(O)/cube.o
OBJSDEBUG= $(ODEBUG)/main.o $(ODEBUG)/cube.o

all: $(O)/freecube

debug: $(ODEBUG)/freecube

clean:
	rm -rf -- $(ODEBUG)
	rm -rf -- $(O)

$(O)/freecube: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) \
	-o $(O)/freecube

$(ODEBUG)/freecube: $(OBJSDEBUG)
	$(CC) $(CFLAGS) $(DEBUG) $(OBJSDEBUG) \
	-o $(ODEBUG)/freecube

$(O)/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(ODEBUG)/%.o: src/%.c
	$(CC) $(CFLAGS) $(DEBUG) -c $< -o $@

$(OBJS) : | $(O)

$(OBJSDEBUG) : | $(ODEBUG)

$(O) :
	mkdir -p $(O)

$(ODEBUG) :
	mkdir -p $(ODEBUG)

