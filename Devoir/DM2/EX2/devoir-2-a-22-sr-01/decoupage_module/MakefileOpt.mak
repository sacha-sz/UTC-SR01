# Définition des variables
CC = gcc
OBJS = main.o explorer.o premier.o my_system.o

# Construction de l'executable
Prog_premiers: $(OBJS)
	$(CC) -o $@ $(OBJS)


# dependances
main.o : explorer.h 
explorer.o : my_system.h  premier.h
premier.o :
my_system.o :

clean:
	rm -rf *.o Prog_premiers