CC = gcc
CFLAG3 = -O3 -Wall -g -o find3
OBJ3 = find3.o utils/util.o utils/bsearcht.o

find3:$(OBJ3)
	$(CC) $(CFLAG3) $(OBJ3) $(LDLIBS)
