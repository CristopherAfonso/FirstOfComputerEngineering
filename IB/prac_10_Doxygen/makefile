CC = g++
CFLAGS = -g -Wall -Weffc++ -O0
OBJ = cripto.o functions_cripto.o 

exercise10: cripto
	rm -f *.o; ls

cripto: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

cripto.o: cripto.cc 
	$(CC) $(CFLAGS) -c $^

functions_cripto.o: functions_cripto.cc 
	$(CC) $(CFLAGS) -c $^
