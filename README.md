# BinaryTree
The executable version of your program is 'bintree'. The makefile ensures this. 
The bintree program supports the following usage:
bintree 'infilename' 'outfilename'
The first argument, 'infilename', is the name of a file that my program parses to generate
the binary search tree. Each line of the input file has a string that is inserted into the binary
search tree, which is initially empty.
• There are no blank lines in the input file.
• Each string in the input file has at least one character and at most 15 characters. Each
character is an upper or lower case letter, a digit or underscore.
• The strings in the input file are all distinct.
The program inserts all the strings in the input file into the binary search tree in the
specified order. Therefore, the first string in the input file becomes the string stored at the root of
the binary search tree, the second string in the input file becomes the string stored at the left or
right child of the root of the binary search tree, and so forth.
After inserting all the strings, the program computes and prints the following information
about the resulting binary search tree to the output file (indicated by inputargument outfile).
1. The total number of strings in the input file.
2. The height of the binary search tree.
3. The number of leaves in the binary search tree.
4. The height of the left subtree of the root.
5. The number of strings in the left subtree of the root.
6. The height of the right subtree of the root.
7. The number of strings in the right subtree of the root.

-- Sean Lachhander
