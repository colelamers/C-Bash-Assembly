
FLAGS = -Wall -lpthread

all: part1 part2

clean:
	rm -f t0 t1

part1: part1.c
	gcc -g -o part1 part1.c $(FLAGS)

t1: t1.c
	gcc -g -I $(INCLUDES) -o t1 t1.c $(FLAGS)
