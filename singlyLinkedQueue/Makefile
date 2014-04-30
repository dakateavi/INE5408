CXX = clang++
LDFLAGS = -lgtest

all: run_tests

run_tests: test
	./$<

clean:
	rm test *.o

test: mainTest.o QueueTest.o
	$(CXX) $(LDFLAGS) -o $@ $^

.c.o:
	$(CXX) -c $<

