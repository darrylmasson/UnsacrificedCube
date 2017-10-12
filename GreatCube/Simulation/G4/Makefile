# --------------------------------------------------------------
# GNUmakefile - Alfio for the XENON Collaboration
# Fri Jun 29 18:30:08 CEST 2012
# --------------------------------------------------------------


name := NSDNeutronGenerator
G4TARGET := $(name)
G4EXLIB := true
MYEXEPATH :=$(G4WORKDIR)/bin/$(G4SYSTEM)
#CPPVERBOSE := true


G4DEBUG := 0

ROOTCFLAGS      = $(shell root-config --cflags)
ROOTGLIBS       = $(shell root-config --glibs)

EXTRALIBS +=$(ROOTGLIBS)


CPPFLAGS += $(ROOTCFLAGS)

.PHONY: all
all: lib bin

include config/binmake.gmk
