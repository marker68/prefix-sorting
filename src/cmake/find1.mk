CC = gcc
CFLAGS = -O3 -Wall -g -fopenmp
CFLAG1 = -o find1
OBJS = find1.o utils/util.o

find1:$(OBJS)
	$(CC) $(CFLAGS) $(CFLAG1) $(OBJS) $(LDLIBS)
