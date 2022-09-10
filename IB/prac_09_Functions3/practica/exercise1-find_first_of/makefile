CC = g++
CFLAGS = -Wall -O0 -g
OBJ = find_first_of.o functions_find_first_of.o 

exercise1: find_first_of
	rm -f *.o 

find_first_of.o: find_first_of.cc 
	$(CC) $(CFLAGS) -c $^

functions_find_first_of.o: functions_find_first_of.cc
	$(CC) $(CFLAGS) -c $^

find_first_of: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^