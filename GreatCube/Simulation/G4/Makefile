CC = g++
SRCDIR := src
INCDIR := include
OBJDIR := obj

#CFLAGS = -g -std=c++11 -Wall -Iinclude -I$(G4INCDIR)
CFLAGS = $(shell /home/darryl/Play/g4-install/bin/geant4-config --cflags) -Iinclude
CPPFLAGS = $(CFLAGS)
LDFLAGS = $(shell /home/darryl/Play/g4-install/bin/geant4-config --libs)
sources := $(wildcard $(SRCDIR)/*.cc)
objects := $(sources:.cc=.o)
EXE = cube

all : $(objects)
	$(CC) $(CPPFLAGS) -o $(EXE) $(objects) $(LDFLAGS)

clean:
	rm -f $(objects) $(deps)
