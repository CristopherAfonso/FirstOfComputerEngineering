CC = g++ 
CFLAGS = -O0 -g 
DEPS = iostream
OBJ = prime.o functions_prime.o 

exercise1: prime 
	rm -f *.o 
	clear

prime.o: prime.cc 
	$(CC) $(CFLAGS) -c $^

functions_prime.o: functions_prime.cc
	$(CC) $(CFLAGS) -c $^

prime: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^