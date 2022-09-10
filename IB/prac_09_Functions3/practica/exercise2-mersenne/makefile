CC = g++ 
CFLAGS = -O0 -g -Wall
OBJ = mersenne.o functions_mersenne.o 

exercise2: mersenne
	rm -f *.o 

mersenne.o: mersenne.cc 
	$(CC) $(CFLAGS) -c $^

functions_mersenne.o: functions_mersenne.cc 
	$(CC) $(CFLGS) -c $^

mersenne: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^