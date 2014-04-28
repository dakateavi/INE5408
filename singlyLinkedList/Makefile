CC = GCC
LDFLAGS = -lgtest

all: run_tests

run_tests: test
	./$<

clean:
	rm test *.o

test: mainTest.o ListTest.o
	clang++ $(LDFLAGS) -o $@ $^

.c.o:
	$(CC) -c $<

