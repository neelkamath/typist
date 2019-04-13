typist.out: main.o test.o accuracy.o save.o
	gcc -o typist.out main.o test.o accuracy.o save.o
main.o: main.c test.h
	gcc -c main.c test.h
test.o: test.c test.h
	gcc -c test.c test.h
accuracy.o: accuracy.c accuracy.h
	gcc -c accuracy.c accuracy.h
save.o: save.c save.h
	gcc -c save.c save.h