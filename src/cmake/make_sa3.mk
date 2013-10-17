CC = gcc
CFLAG9 = -O3 -Wall -g  -o make_sa3
OBJ9 = make_sa3.o utils/util.o utils/quicksort.o

make_sa3:$(OBJ9)
	$(CC) -fopenmp $(CFLAG9) $(OBJ9) $(LDLIBS)