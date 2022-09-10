CC = g++ 
CFLAGS = -O0 -g -Wall -Weffc++
OBJ = armstrong_numbers.o functions_armstrong_numbers.o 

exercise3: armstrong_numbers
	rm -f *.o 

armstrong_numbers.o: armstrong_numbers.cc 
	$(CC) $(CFLAGS) -c $^

functions_armstrong_numbers.o: functions_armstrong_numbers.cc 
	$(CC) $(CFLAGS) -c $^

armstrong_numbers: $(OBJ) 
	$(CC) $(CFLAGS) -o $@ $^
