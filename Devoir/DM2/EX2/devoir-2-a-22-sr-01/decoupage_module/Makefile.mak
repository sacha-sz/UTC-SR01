Prog_premiers : main.o explorer.o premier.o my_system.o
	gcc main.o explorer.o premier.o my_system.o -o Prog_premiers 
main.o : main.c explorer.h 
	gcc -c main.c
explorer.o : explorer.c my_system.h explorer.h premier.h
	gcc -c explorer.c
premier.o : premier.c premier.h
	gcc -c premier.c
my_system.o : my_system.c my_system.h
	gcc -c my_system.c
clean : 
	rm my_system.o premier.o explorer.o main.o Prog_premiers 
