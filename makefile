CFLAGS=-Wall
LIBS=-lcheck -lm -pthread -lrt

all: test

test: RomanNumTesting
	./RomanNumTesting

RomanNumTesting: RomanNum_TEST.o RomanNum.o
	gcc -o RomanNumTesting RomanNum.o RomanNum_TEST.o $(LIBS)

RomanNum_TEST.o: RomanNum_TEST.c RomanNum.h
	gcc $(CFLAGS) -c RomanNum_TEST.c

RomanNum_TEST.c: RomanNum_TEST.check
	checkmk RomanNum_TEST.check >RomanNum_TEST.c

Clean:
	rm *o RomanNumTesting
