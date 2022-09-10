CC = g++
CFLAGS = -O0 -g
DEPS = iostream
OBJ = palindrome_numbers.o functions5.o 

exercise5: palindrome_numbers
	rm -f *.o 
	clear
palindrome_numbers.o: palindrome_numbers.cc 
	$(CC) $(CFLAGS) -c $^

functions5.o: functions5.cc
	$(CC) $(CFLAGS) -c $^

palindrome_numbers: $(OBJ) 
	$(CC) $(CFLAGS) -o $@ $^