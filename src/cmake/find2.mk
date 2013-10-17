CC = gcc
CFLAG2 = -O3 -Wall -g -o find2
OBJ2 = find2.o utils/util.o utils/bsearcht.o

find2:$(OBJ2)
	$(CC) $(CFLAG2) $(OBJ2) $(LDLIBS)