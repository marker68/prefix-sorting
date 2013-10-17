CC = gcc
CFLAG6 = -O3 -Wall -g -o sa_find2
OBJ6 = sa_find2.o utils/bsearcht.o utils/util.o

sa_find2:$(OBJ6)
	$(CC) $(CFLAG6) $(OBJ6) $(LDLIBS)