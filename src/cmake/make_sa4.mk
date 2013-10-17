CC = gcc
CFLAG10 = -O3 -Wall -g  -o make_sa4
OBJ10 = make_sa4.o utils/util.o utils/inducedsort.o

make_sa4:$(OBJ10)
	$(CC) $(CFLAG10) $(OBJ10) $(LDLIBS)