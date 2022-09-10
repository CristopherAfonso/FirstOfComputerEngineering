CC = g++ 
CFLAGS = -O0 -g -Wall
OBJ = mersenne2.o functions_mersenne2.o 

exercise_class: mersenne2
	rm -f *.o 

mersenne2.o: mersenne2.cc 
	$(CC) $(CFLAGS) -c $^

functions_mersenne2.o: functions_mersenne2.cc 
	$(CC) $(CFLGS) -c $^

mersenne2: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^
