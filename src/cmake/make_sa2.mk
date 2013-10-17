CC = gcc
CFLAG8 = -O3 -Wall -g -o make_sa2
OBJ8 = make_sa2.o utils/util.o

make_sa2:$(OBJ8)
	$(CC) $(CFLAG8) $(OBJ8) $(LDLIBS)