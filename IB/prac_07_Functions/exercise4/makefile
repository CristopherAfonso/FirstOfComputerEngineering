CC = g++
CFLAGS = -O0 -g
DEPS = iostream
OBJ = days_months.o functions4.o 

exercise4: days_months
	rm -f *.o 

days_months.o: days_months.cc 
	$(CC) $(CFLAGS) -c $^

functions4.o: functions4.cc
	$(CC) $(CFLAGS) -c $^

days_months: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^