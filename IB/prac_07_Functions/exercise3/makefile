CC = g++
CFLAGS = -O0 -g
DEPS = iostream
OBJ = taylor_serie.o functions3.o

exercise3: taylor_serie
	rm -f *.o
	
taylor_serie: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

taylor_serie.o: taylor_serie.cc 
	$(CC) $(CFLAGS) -c $^

functions3.o: functions3.cc 
	$(CC) $(CFLAGS) -c $^