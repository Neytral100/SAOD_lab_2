waybin = bin/
wayobj = obj/
waysrc = src/
objects = $(wayobj)main.o $(wayobj)bstree.o $(wayobj)hashtab.o
exeflags =  -Wall -Werror
objflags = -c -Wall
exe = $(waybin)prog

all: obj bin $(exe) 

$(exe): $(objects)
	gcc -o $(exe) $(exeflags) $(objects)

$(wayobj)main.o: $(waysrc)main.c
	gcc $(objflags) $(waysrc)main.c -o $(wayobj)main.o

$(wayobj)bstree.o: $(waysrc)bstree.c
	gcc $(objflags) $(waysrc)bstree.c -o $(wayobj)bstree.o

$(wayobj)hashtab.o: $(waysrc)hashtab.c
	gcc $(objflags) $(waysrc)hashtab.c -o $(wayobj)hashtab.o

obj:
	mkdir obj

bin:
	mkdir bin
	
.PHONY: clean

clean:
	rm -f $(exe) $(wayobj)*.o