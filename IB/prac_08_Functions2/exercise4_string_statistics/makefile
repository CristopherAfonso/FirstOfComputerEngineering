CC = g++ 
CFLAGS = -O0 -g
DEPS = iostream
OBJ = string_statistics.o functions_string_statistics.o

exercise4: string_statistics
	rm -f *.o 
	clear

string_statistics.o: string_statistics.cc 
	$(CC) $(CFLAGS) -c $^

functions_string_statistics.o: functions_string_statistics.cc
	$(CC) $(CFLAGS) -c $^

string_statistics: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^