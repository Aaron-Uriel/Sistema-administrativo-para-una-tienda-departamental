CC        = g++
cc        = gcc
FLAGS     ?= -O3 -pipe
SRCDIR    = src
RM        ?= rm
SOURCES   =
SRCLIST   =
#Obtener el código fuente
ifdef OS
	SOURCES = $(shell dir /B /S $(SRCDIR)/*.cpp $(SRCDIR)/*.c)
	RM = rem
else
	#$(dir $(SRCDIR)/*.cpp $(SRCDIR)/*.c)
	SOURCES = $(shell find $(SRCDIR) -name *.cpp -or -name *.c)
endif
OBJDIR    = obj
OBJECTS   = $(SOURCES:$(SRCDIR)/%=$(OBJDIR)/%.o)
BINDIR    = bin
BINNAME   = a
OUTPUT    = $(BINDIR)/$(BINNAME)
WARNFLAGS = -Wall -Wextra

.PHONY: all
all:
	$(RM) $(BINDIR)/$(BINNAME)
all: $(OUTPUT)
$(OUTPUT): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $(OUTPUT)

$(OBJDIR)/%.cpp.o: $(SRCDIR)/%.cpp
	$(CC) $(FLAGS) $(WARNFLAGS) $(DEFINES) -c $< -o $@

$(OBJDIR)/%.c.o: $(SRCDIR)/%.c
	$(cc) $(FLAGS) $(WARNFLAGS) $(DEFINES) -c $< -o $@

clear:
	$(RM) $(OBJDIR)/*.o

debug: FLAGS = -g -Og
debug: all
debug: DEFINES = -DDEBUG

all: clear