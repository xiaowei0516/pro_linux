CC = gcc

module: main.o bicycle.o trunk.o
		$(CC) -o $@ $^

%.o: %.c
		$(CC) -c -I. $< -o $@


clean:
		rm -f *.o module

