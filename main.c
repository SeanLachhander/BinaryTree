/*
 * main.c
 *
 *  Created on: Nov 4, 2016
 *      Author: seanlachhander
 */
// Sean Lachhander -- slachhander@albany.edu -- CSI 402 -- Programming Assignment #4

#include "header.h"

typedef struct binarytreenode {
  char string[16];
  struct binarytreenode * left_child, * right_child; // left child | right child
  int rightTree;
  int leftTree;
}
binarytreenode;

struct node {
  int nxm;
  struct node * left, * right;
};

binarytreenode * insertNode(binarytreenode * node, char str[15]) {
  if (node == NULL) {
    node = (binarytreenode * ) malloc(sizeof(binarytreenode));
    strncpy(node - > string, str, 15);
    node - > left_child = NULL;
    node - > right_child = NULL;
  } else if (strcmp(node - > string, str) > 0) {
    node - > right_child = insertNode(node - > right_child, str);
    node - > rightTree++;
  } else if (strcmp(node - > string, str) < 0) {
    node - > left_child = insertNode(node - > left_child, str);
    node - > leftTree++;
  }
  return node;
}

// to find number of nodes along the longest path from the root node
// down to the farthest leaf node.
int binaryTreeHeight(struct binarytreenode * node) {
  if (node == NULL)
    return 0;
  else {
    // compute the depth of each subtree
    int lHeight = binaryTreeHeight(node - > left_child);
    int rHeight = binaryTreeHeight(node - > right_child);

    // use the larger depth
    if (binaryTreeHeight(node - > left_child) < binaryTreeHeight(node - > right_child)) {
      rHeight++;
      return rHeight;
    } else {
      lHeight++;
      return lHeight;
    }
  }
}

//used to get the height of the tree and then called on the left and right root
//nodes to get the height of left and right subtrees when needed

int maxmHeight(struct binarytreenode * node) {
  if (node == NULL)
    return 0;
  else {
    /* compute the depth of each subtree in maxmHeight function*/
    int lHeight = maxmHeight(node - > left_child);
    int rHeight = maxmHeight(node - > right_child);

    // uses the larger one
    if (lHeight > rHeight) {
      return lHeight + 1;
    } else {
      return rHeight + 1;
    }
  }
}

//function to count the left and right leafs of the tree(leafs are the end nodes)
int leaves(struct binarytreenode * leaf) {
  if (leaf == NULL) {
    return 0;
  } else if ((leaf - > left_child == NULL) && (leaf - > right_child == NULL)) {
    return 1;
  } else {
    int lDepth = leaves(leaf - > left_child);
    int rDepth = leaves(leaf - > right_child);
    int total = lDepth + rDepth;
    return total;
  }
}

int main(int argc, char * argv[]) {
  // Start error checking
  if (argc < 3 || argc > 3) {
    printf("Command line error...");
    fprintf(stderr, "Usage: %s file\n", argv[0]);
    exit(1);
  }

  // read in file
  FILE * inFile = fopen(argv[1], "r");
  // if file null, error message

  if (inFile == NULL) {
    printf("Input file error...");
    fprintf(stderr, "Could not open file: %s\n", argv[1]);
    exit(1);
  }

  // outfile with write privileges
  FILE * outFile = fopen(argv[2], "w");
  if (outFile == NULL) {
    printf("Output file error...");
    fprintf(stderr, "Could not open file: %s\n", argv[2]);
    exit(1);
  }

  outFile = fopen(argv[2], "w");

  char str[16]; // directions stated no more than 15 maximum.
  int strn = 0; // start count at 0
  binarytreenode * root = NULL;
  while (fscanf(inFile, "%s", str) != -1) { // while not end of file loop
    root = insertNode(root, str); // insert node from root to tree comparisons made
    strn++; // increment count for strings in the input file
  }
  // file prints
  fprintf(outFile, "No. of strings in the input file =  %d\n", strn);
  fprintf(outFile, "Height of the search tree =  %d \n", (binaryTreeHeight(root)) - 1);
  fprintf(outFile, "Number of leaves in the tree =  %d\n", leaves(root));
  fprintf(outFile, "Height of the left subtree of root   =  %d \n", (maxmHeight(root - > right_child)) - 1);
  fprintf(outFile, "No. of strings in the left subtree =  %d\n", root - > rightTree);
  fprintf(outFile, "Height of the right subtree of root  =  %d \n", (maxmHeight(root - > left_child)) - 1);
  fprintf(outFile, "No. of strings in the right subtree =  %d\n", root - > leftTree);

  return 0;
}
