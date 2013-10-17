CC = gcc
CFLAG7 = -O3 -Wall -g -o sa_find3
OBJ7 = sa_find3.o utils/bsearcht.o utils/util.o

sa_find3:$(OBJ7)
	$(CC) $(CFLAG7) $(OBJ7) $(LDLIBS)