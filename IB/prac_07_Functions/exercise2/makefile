CC = g++
CFLAGS = -O0 -g
DEPS = iostream
OBJ = palindroma.o functions2.o


palindrome: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^
	rm -f *.o

palindroma.o: palindroma.cc
	$(CC) $(CFLAGS) -c $^

functions2.o: functions2.cc
	$(CC) $(CFLAGS) -c $^