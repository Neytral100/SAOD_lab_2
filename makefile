waybin = bin/
wayobj = obj/
waysrc = src/
objects = $(wayobj)main.o $(wayobj)bstree.o $(wayobj)hashtab.o $(wayobj)experiment1.o
exeflags =  -Wall -Werror
objflags = -c -Wall
exe = $(waybin)prog

all: obj bin $(exe) 

$(exe): $(objects)
	gcc -o  $(exe) -O0 $(exeflags) $(objects)

$(wayobj)main.o: $(waysrc)main.c
	gcc $(objflags) $(waysrc)main.c -g -o $(wayobj)main.o

$(wayobj)bstree.o: $(waysrc)bstree.c
	gcc $(objflags) $(waysrc)bstree.c -g -o $(wayobj)bstree.o

$(wayobj)hashtab.o: $(waysrc)hashtab.c
	gcc $(objflags) $(waysrc)hashtab.c -g -o $(wayobj)hashtab.o

$(wayobj)experiment1.o: $(waysrc)experiment1.c
	gcc $(objflags) $(waysrc)experiment1.c -g -o $(wayobj)experiment1.o

obj:
	mkdir obj

bin:
	mkdir bin
	
.PHONY: clean

clean:
	rm -f $(exe) $(wayobj)*.o