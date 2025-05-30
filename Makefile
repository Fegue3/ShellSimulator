#A Simple Example Makefile for soshell
#
# Syntax:
# Alvo: Dependencias
# tab Action 1
# tab Action 2
#
# Variaveis: compiler, compiler flags, libraries to link, names of the object files for the executable.
#
CC=cc
FLAGS=-c -Wall
LIBS=-lm -lreadline
OBS=main.o execute.o parse.o socp.o calc.o files.o display.o redirects.o threads.o fileutils.o

#Alvo por defeito é o primeiro
all :  soshell

redirects.o : shell.h redirects.c
	$(CC) $(FLAGS) redirects.c

main.o : shell.h main.c
	$(CC) $(FLAGS) main.c
execute.o : shell.h execute.c
	$(CC) $(FLAGS) execute.c
parse.o : shell.h parse.c
	$(CC) $(FLAGS) parse.c
	
display.o : shell.h display.c
	$(CC) $(FLAGS) display.c

files.o : shell.h files.c
	$(CC) $(FLAGS) files.c

calc.o : shell.h calc.c
	$(CC) $(FLAGS) calc.c

socp.o : shell.h socp.c
	$(CC) $(FLAGS) socp.c

threads.o : shell.h threads.c
	$(CC) $(FLAGS) threads.c

fileutils.o : shell.h fileutils.c
	$(CC) $(FLAGS) fileutils.c

soshell : $(OBS)
	$(CC)  -o soshell  $(OBS) $(LIBS)
clean limpar:
	rm -f soshell *.o
	rm -f *~
	rm -f .soshell_history
	echo "Remover: Ficheiros executáveis, objetos e temporários."
