#!/bin/bash

RM := rm -rf
MKDIR := 
CC:=gcc
CFLAGS:= -g -Wall 
CLIBS:=-lm


vpath %.c src
vpath %.h include


sources=$(wildcard src/*c)
objects=$(subst .o,.c,$(sources))

TARGET := 

all: main
	echo "finsihed"


main : $(objects)
	$(CC) $(CFLAGS) *.o -o $@ $(CLIBS) 

%.o : %.c
	$(CC) $(CFLAGS) -c $^ $(CLIBS) 

install : main
	sudo cp build/main /usr/bin/aimath
	 
	

clean:
	$(RM) *.o
