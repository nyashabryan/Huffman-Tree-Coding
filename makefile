# Makefile for C++ programs
# Nyasha Bryan Katemauswa
# 24 February 2019

# include dependencies; rules below
ifeq ($(UNAME),incl.defs)
	include incl.defs
endif

# Directories
SRC=./src
BIN=./bin

CC=g++
CCFLAGS=-std=c++11
SOURCES=huffmannode.cpp huffmantree.cpp huffencode.cpp
OBJECTS=huffmannode.o huffmantree.o huffencode.o

main: $(OBJECTS)
	$(CC) $(CCFLAGS) $(OBJECTS) -o huffencode $(LIBS)

.cpp.o:
	$(CC) $(CCFLAGS) -c $<

# Type "make depend" to make dependencies
depend:
	$(CC) -M $(SOURCES) > incl.defs

run:
	./huffencode inputfile outputfile

clean:
	rm *.o
	rm huffencode
	rm incl.defs

remove_tar:
	rm *.tar.gz

tar:
	tar -zcvf KTMNYA001.tar.gz makefile README.md *.cpp *.h *.py .git .gitignore