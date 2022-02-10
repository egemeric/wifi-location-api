LDEXTRAFLAGS=-rdynamic


# project name (generate executable with this name)
TARGET   = wifiScan

CC       = gcc
# compiling flags here
CFLAGS   = -std=c99 -Wall -I.


PKGCONFIG = $(shell which pkg-config)


LINKER   = gcc

LFLAGS   = -Wall -I. -lm  -pthread
LFLAGS   += -lmnl

SRCDIR   = src
OBJDIR   = obj
BINDIR   = bin

SOURCES  := $(wildcard $(SRCDIR)/*.c)
INCLUDES := $(wildcard $(SRCDIR)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
rm       = rm -f

$(BINDIR)/$(TARGET): $(OBJECTS)
	@$(LINKER) $(LDEXTRAFLAGS) $(OBJECTS) $(LFLAGS) -o $@

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) $(LDEXTRAFLAGS) -c $< -o $@

.PHONY: clean
clean:
	@$(rm) $(OBJECTS)
	@echo "Cleanup complete!"

.PHONY: remove
remove: clean
	@$(rm) $(BINDIR)/$(TARGET)
	@echo "Executable removed!"
