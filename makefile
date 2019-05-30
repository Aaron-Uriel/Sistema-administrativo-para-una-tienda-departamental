CC        = g++
cc        = gcc
FLAGS     ?= -O3 -pipe
SRCDIR    = src
CSOURCES  = $(wildcard $(SRCDIR)/*.c)
CPPSOURCES= $(wildcard $(SRCDIR)/*.cpp)
OBJDIR    = obj
COBJECTS  = $(CSOURCES:$(SRCDIR)/%=$(OBJDIR)/%.o)
CPPOBJECTS= $(CPPSOURCES:$(SRCDIR)/%=$(OBJDIR)/%.o)
BINDIR    = bin
BINNAME   = a
OUTPUT    = $(BINDIR)/$(BINNAME)
WARNFLAGS = -Wall -Wextra

.PHONY: all
all: $(OUTPUT)
$(OUTPUT): $(COBJECTS) $(CPPOBJECTS)
	$(CC) $(CPPOBJECTS) $(COBJECTS) $(LDFLAGS) -o $(OUTPUT)

$(OBJDIR)/%.cpp.o: $(SRCDIR)/%.cpp
	$(CC) $(FLAGS) $(WARNFLAGS) $(DEFINES) -c $< -o $@

$(OBJDIR)/%.c.o: $(SRCDIR)/%.c
	$(cc) $(FLAGS) $(WARNFLAGS) $(DEFINES) -std=c11 -c $< -o $@

clear:
	rm $(OBJDIR)/*.o

debug: FLAGS = -g -Og
debug: all
debug: DEFINES = -DDEBUG

all: clear