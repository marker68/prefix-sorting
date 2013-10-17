CC = gcc
CFLAG4 = -O3 -Wall -g -o make_sa_find4
OBJ4 = make_sa_find4.o utils/bsearcht.o

make_sa_find4:$(OBJ4)
	$(CC) $(CFLAG4) $(OBJ4) $(LDLIBS)
