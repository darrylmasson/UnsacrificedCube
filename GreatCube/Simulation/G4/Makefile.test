CC = g++
SRCDIR := src
INCDIR := include
OBJDIR := obj
DEPDIR := include

#CFLAGS = -g -std=c++11 -Wall -Iinclude -I$(G4INCDIR)
CFLAGS = $(shell /home/darryl/Play/g4-install/bin/geant4-config --cflags)
CPPFLAGS = $(CFLAGS)
LDFLAGS = $(shell /home/darryl/Play/g4-install/bin/geant4-config --libs)
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.d
sources := $(wildcard $(SRC)/*.cc)
objects := $(sources:%.cc=$(OBJDIR)/%.o)
deps := $(sources:%.cc=$(DEPDIR)/%.d)
EXE = cube

all : $(objects)
	$(CC) $(CPPFLAGS) $(DEPFLAGS) -o $(EXE) $(objects) $(LDFLAGS)

$(OBJDIR)/%.o : $(SRCDIR)/%.cc $(INCDIR)/%.hh $(DEPDIR)/%.d
	$(CC) $(CPPFLAGS) -c -o $(OBJDIR)/$@ $<

$(deps):
include $(wildcard $(deps))

clean:
	rm -f $(objects) $(deps)
