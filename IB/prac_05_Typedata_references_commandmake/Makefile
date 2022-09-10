CC = g++
CFLAGS = -O0 -g
DEPS = iostream
OBJ = data_types.o references.o boolean_operators.o arithmetic_operators.o 


ib_practica_5: data_types references boolean_operators arithmetic_operators
	rm -f $(OBJ)

data_types.o: data_types.cc
	$(CC) -c $(CFLAGS) $^

data_types: data_types.o
	$(CC) -o $@ $^

references.o: references.cc
	$(CC) -c $(CFLAGS) $^

references: references.o
	$(CC) -o $@ $^

boolean_operators.o: boolean_operators.cc
	$(CC) -c $(CFLAGS) $^

boolean_operators: boolean_operators.o
	$(CC) -o $@ $^ 

arithmetic_operators.o: arithmetic_operators.cc
	$(CC) -c $(CFLAGS) $^

arithmetic_operators: arithmetic_operators.o
	$(CC) -o $@ $^
