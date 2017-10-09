#ifndef TREE_H
#define TREE_H

// Structures
struct s_node;
struct s_list_of_nodes;

// typedefying
typedef struct s_node* tree;
typedef struct s_list_of_nodes* list;

// Structure of the doubly linked list of nodes
struct s_list_of_nodes
{
    tree node;
    list next;
    list prev;
};

// Structure of the node, linked to its father, with list of the sons
struct s_node
{
    int value;
    list father;
    list sons_start_dummy;
    list sons_end_dummy;
};

extern list initialize_dummy();

extern tree initialize_node(int num_node, list father);

extern tree initialize_root();

extern void ADD_NODE(tree node, int* n, tree* array_of_addresses);

extern int RIGHTMOST_CHILD(tree node);

extern void DELETE_SUBTREE(tree node, int* nodes_counter);

extern void DELETE_NODE(tree node);

extern void SPLIT_NODE(tree father, tree son, int* n,tree* array_of_addresses);

#endif /* TREE_H */