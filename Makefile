all: tp1a.o
	gcc tp1a.o -o tp1a -lm

tp1a.o: tp1a.c
	gcc -c -g tp1a.c

clean:
	rm -rf *.o

mrproper: clean
	rm -i tp1a
