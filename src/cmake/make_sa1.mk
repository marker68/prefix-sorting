CC = gcc
CFLAG5 = -O3 -Wall -g -o make_sa1
OBJ5 = make_sa1.o utils/util.o

make_sa1:$(OBJ5)
	$(CC) $(CFLAG5) $(OBJ5) $(LDLIBS)