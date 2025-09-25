CC=gcc
CFLAGS=-I. -lm -g
DEPS = *.h
OBJ = Question1.o Question2.o testCases.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

Lab3: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

#testCompile: AllTests.c testCases.c CuTest.c Question1.c
#	gcc -o testLab0 AllTests.c testCases.c CuTest.c Question1.c

test:	testLab3
testLab3:
# next line must start with a real TAB (ASCII 9)
	./run.sh

.PHONY: clean

clean:
	$(RM) *.o *.exe Lab3
