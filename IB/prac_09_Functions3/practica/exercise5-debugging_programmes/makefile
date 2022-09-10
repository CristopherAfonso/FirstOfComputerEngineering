CC = g++
CFLAGS = -O0 -g -Wall -Weffc++ -std=c++14

factorial_fixed_up: factorial_fixed_up.cc
	$(CC) $(CFLAGS) -o $@ $^
	rm -f *.o

.PHONY: factorial_fixed_up fibonacci_fixed_up

fibonacci_fixed_up: fibonacci_fixed_up.cc
	$(CC) $(CFLAGS) -o $@ $^
	rm -f *.o

.PHONY: fibonacci_fixed_up multiples_3_5_fixed_up

multiples_3_5_fixed_up: multiples_3_5_fixed_up.cc 
	$(CC) $(CFLAGS) -o $@ $^
	rm -f *.o

.PHONY: multiples_3_5_fixed_up sum_serie_fixed_up

sum_serie_fixed_up: sum_serie_fixed_up.cc
	$(CC) $(CFLAGS) -o $@ $^
	rm -f *.o
