#include "header.h"

struct node
{
char *word;
struct node *left_child,*right_child;
};

int stringsinInput = 0;
int leftcount = 0;
int rightcount = 0;

struct node *inserttree(struct node *tree, char *s){
int i;

if (tree==NULL){
	if ((tree=(struct node *)malloc(sizeof (struct node)))!=NULL)
		if ((tree->word=(char *) malloc(strlen(s)+1))==NULL)
		{
			free(tree);
			tree=NULL;
		}
		else
		{
			stringsinInput++;
			tree->left_child = NULL;
			tree->right_child = NULL;
			strcpy(tree->word,s);
		}
	}
	else if ((i=strcmp(tree->word,s))>0){
		tree->left_child=inserttree(tree->left_child,s);
		leftcount++;
	}
	else if (i<0) {
		tree->right_child=inserttree(tree->right_child,s);
		rightcount++;
	}
return tree;
}


void printtree(struct node *tree){
	if (tree!=NULL)
	{
		printtree(tree->left_child);
		printf("%s",tree->word);
		printtree(tree->right_child);

	}
}

void freetree(struct node *tree){
	if (tree!=NULL)
	{
		free(tree->word);
		freetree(tree->left_child);
		freetree(tree->right_child);
		free(tree);
	}
}


int main(int argc, char *argv[]){
	if(argc > 3 || argc < 3){
			printf("Command line error\n");
			exit(1);
		}
		FILE *f;
		f = fopen(argv[1], "r");
		/*if(f == NULL){
			printf(stderr, "Couldn't open the file: %s\n", f);
			exit(1);
		} */
char s[16]; // assume 15 char
struct node *tree=NULL;

if (f == NULL){
printf("Unable to open Test.txt");
}
else
{
while (fscanf(f,"%16s",s)!=EOF)
tree=inserttree(tree,s);
fclose(f);
printtree(tree);
printf("\nNo. of strings in the input file = %d", stringsinInput);
printf("\nHeight of the search tree = --");
printf("\nNumber of leaves in the tree = --");
printf("\nHeight of the left_child subtree of root = --");
printf("\nNo. of strings in the left subtree of the root = %d", leftcount);
printf("\nHeight of the right_child subtree of root = --");
printf("\nNo. of strings in the right subtree of the root = %d\n", rightcount);

freetree(tree);
}
return 0;
}
