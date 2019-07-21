all:steg
steg:main.o leiturappm.o leiturabmp.o leituramsg.o converter.o 
	gcc -o steg leiturappm.o leiturabmp.o leituramsg.o main.o converter.o
leiturappm.o:leiturappm.c leiturappm.h 
	gcc -Wall -pedantic -ansi -std=c11 -c leiturappm.c
leiturabmp.o:leiturabmp.c leiturabmp.h
	gcc -Wall -pedantic -ansi -std=c11 -c leiturabmp.c
leituramsg.o:leituramsg.c leituramsg.h
	gcc -Wall -pedantic -ansi -std=c11 -c leituramsg.c
main.o:main.c
	gcc -Wall -pedantic -ansi -std=c11 -c main.c
converter.o:converter.c converter.h
	gcc -Wall -pedantic -ansi -std=c11 -c converter.c
clean:
	rm -f core steg main.o leiturappm.o leiturabmp.o leituramsg.o converter.o
