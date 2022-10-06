all: tp1a.o matrice.o sequence.o hadamard.o listSeq.o message.o
	gcc listSeq.o hadamard.o matrice.o sequence.o message.o tp1a.o -o tp1a -lm

clean: 
	rm -rf *.o

mrproper: clean
	rm -i tp1a
