BASE = ../


ODIR = $(BASE)obj/
CODE = $(BASE)code/
TOOLS = $(BASE)tools/
TEST = $(BASE)test/


COFILE = $(ODIR)automata.o  $(ODIR)dictionary.o 
HOFILE = $(CODE)automata.h  $(CODE)dictionary.h
TestOFile = $(TEST)main.o

OPTION = -O0 
#OPTION = -O3
EXTRA =-Wall -Wextra -fno-strict-aliasing -fwrapv -fno-aggressive-loop-optimizations -Wconversion -ftrapv
CC = icc
#CC = g++

libautomata.a:  $(COFILE)
	ar -rcv $(BASE)libautomata.a  $(COFILE)

$(ODIR)automata.o:$(CODE)automata.cpp $(CODE)automata.h
	$(CC) -o $(ODIR)automata.o -c $(EXTRA) $(OPTION) $(CODE)automata.cpp
	$(CC) -o $(ODIR)automata_.asm -S $(EXTRA) $(OPTION) $(CODE)automata.cpp

$(ODIR)dictionary.o:$(CODE)dictionary.cpp $(CODE)dictionary.h $(CODE)automata.h
	$(CC) -o $(ODIR)dictionary.o -c $(EXTRA) $(OPTION) $(CODE)dictionary.cpp

test.exe: $(COFILE) $(TestOFile)
	$(CC) -o $(TEST)test.exe $(COFILE) $(TestOFile)

$(TEST)main.o: $(HOFILE) $(TEST)main.cpp
	$(CC) -o $(TEST)main.o -c $(OPTION) $(TEST)main.cpp




.PHONY: clean
clean:
	rm $(ODIR)*.o
	rm $(TEST)*.o







