bintree:				main.o treeheight.o leaves.o
						gcc main.o treeheight.o leaves.o -o bintree

main.o:					main.c 
						gcc -c main.c

treeheight.o:			treeheight.c
						gcc -c treeheight.c
						
leaves.o:				leaves.c
						gcc -c leaves.c
						
						