CC        = g++
cc        ?= gcc
FLAGS     ?= -O3 -pipe
SRCDIR    = src
SOURCES   = $(shell find $(SRCDIR) -name *.cpp -or -name *.c)
OBJDIR    = obj
OBJECTS   = $(SOURCES:$(SRCDIR)/%=$(OBJDIR)/%.o)
BINDIR    = bin
BINNAME   = a.out
OUTPUT    = $(BINDIR)/$(BINNAME)
WARNFLAGS = -Wall -Wextra
LDFLAGS   ?=
DEFINES   ?= -DNBDEBUG
STDC++    ?= -std=c++17

.PHONY: all
all: $(OUTPUT)

$(OUTPUT): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $(OUTPUT)

$(OBJDIR)/%.cpp.o: $(SRCDIR)/%.cpp
	$(CC) $(FLAGS) $(WARNFLAGS) $(DEFINES) $(STDC++) -c $< -o $@

$(OBJDIR)/%.c.o: $(SRCDIR)/%.c
	$(cc) $(FLAGS) $(WARNFLAGS) $(DEFINES) -c $< -o $@

clear:
	rm $(OBJDIR)/*.o $(BINDIR)/*.out

clean:
	rm $(OBJDIR)/*.o $(BINDIR)/*.out

debug: FLAGS = -g -Og
debug: all
debug: DEFINES = -DDEBUG

windows: cc = x86_64-w64-mingw32-gcc
windows: CC = x86_64-w64-mingw32-g++
windows: BINNAME = a.exe
windows: LDFLAGS =  
windows: all
