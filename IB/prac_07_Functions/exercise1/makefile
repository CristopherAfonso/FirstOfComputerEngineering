CC = g++
CFLAGS = -O0 -g
DEPS = iostream
OBJ = primes.o functions1.o


exercise1: primes
	rm -f $(OBJ)

primes.o: primes.cc
	$(CC) -c $(CFLAGS) $^

functions1.o: functions1.cc
	$(CC) -c $(CFLAGS) $^

primes: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^