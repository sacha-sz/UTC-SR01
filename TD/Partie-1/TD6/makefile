HEADERS = $(wildcard *.h)
SRC = $(wildcard *.c)
OBJ = $(wildcard *.o)

resultat: $(OBJ) $(HEADERS)
	gcc -o $(OBJ)

%.o: %.c
	gcc -c $^

.PHONY : clean

clean:
	rm –rf *.o