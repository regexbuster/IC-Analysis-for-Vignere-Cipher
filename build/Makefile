all: vignere frequency

vignere: vignere.o
	gcc vignere.o -o vignere

vignere.o: ../src/vignere.c
	gcc -c ../src/vignere.c -o vignere.o

frequency: frequency.o
	gcc frequency.o -o frequency

frequency.o: ../src/frequency.c
	gcc -c ../src/frequency.c -o frequency.o


