CC = g++ 
CFLAGS = -O0 -g
DEPS = iostream
OBJ = vector_statistics.o functions_vector_statistics.o 

exercise3: vector_statistics
	rm -f *.o 

vector_statistics.o: vector_statistics.cc 
	$(CC) $(CFLAGS) -c $^

functions_vector_statistics.o: functions_vector_statistics.cc 
	$(CC) $(CFLAGS) -c $^

vector_statistics: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^