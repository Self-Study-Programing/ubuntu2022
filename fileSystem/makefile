all: file_test
 
file_test: main.o fileposition.o
	gcc -o file_test main.o fileposition.o

main.o : main.c fileposition.o
	gcc -c main.c fileposition.o

fileposition.o : fileposition.h fileposition.c
	gcc -c fileposition.h fileposition.c

# file.o: sum.h sum.cpp
#     g++ -c -o sum.o sum.cpp
 
clean:
	rm -f file_test *.o *.h.gch