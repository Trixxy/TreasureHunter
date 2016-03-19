CC       = g++
CFLAGS   = -std=c++11 -g -lpthread -lboost_system -lncurses

LINKER   = g++ -o
LFLAGS   = -Wall -I. -lm 

SRCDIR   = ./
OBJDIR   = ./
BINDIR   = ./

SOURCES := $(wildcard $(SRCDIR)/*.cpp)
OBJECTS := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))
TARGET   = $(BINDIR)/main



all: $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

run: all
	$(TARGET)