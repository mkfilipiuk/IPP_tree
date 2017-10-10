# Tree
Implementation of a tree-like structure based on doubly linked list.
## Supported operations
### ADD_NODE <k>
Adding new node linked to k-th one. It becomes his most right child.
### RIGHTMOST_CHILD <k>
Prints out the most right child of the k-th node. If k is a leaf, it prints out -1.
### DELETE_NODE <k>
Removes the k-th node. Its children become children of its parent.
### DELETE_SUBTREE <k>
Deletes k-th node with its subtree
### SPLIT_NODE <k> <w>
Creates a node with k-th one as a parent and nearest right sibling to w-th node. Children of k-th node, on the right of w-th node become children on the new node.
## Standard error
Calling function with -v parameter prints at stderr line:
NODES: <n>
where <n> is number of nodes at the structure. 
## Testing 
You can call:
./test.sh <prog> <dir>
script runs <prog> program for each file with .in extension from directory <dir> (<dir>/*.in) and compares it with corresponding .out files. Calling ./test.sh -v <prog> <dir> checks also stderr output values with files .err . 
