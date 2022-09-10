CC = g++ 
CFLAGS = -O0 -g
DEPS = iostream
OBJ = difference_of_squares.o functions_difference_of_squares.o

exercise2: difference_of_squares
	rm -f *.o 

difference_of_squares.o: difference_of_squares.cc 
	$(CC) $(CFLAGS) -c $^

functions_difference_of_squares.o: functions_difference_of_squares.cc 
	$(CC) $(CFLAGS) -c $^

difference_of_squares: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^