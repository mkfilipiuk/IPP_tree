#include<stdio.h>
#include<stdlib.h>

#include "tree.h"

// Initialisation of the list's dummy

list initialize_dummy()
{
	list dummy = (list) malloc(sizeof(struct s_list_of_nodes));
	dummy->node = NULL;
	return dummy;
}

// Initialisation of the tree. Arguments: number of new node, adresse of father's list element

tree initialize_node(int num_node, list father)
{
	tree a_node = malloc(sizeof(struct s_node));
	a_node->value = num_node;
	a_node->father = father;
	a_node->sons_start_dummy = initialize_dummy();
	a_node->sons_end_dummy = initialize_dummy();
	a_node->sons_start_dummy->prev = NULL;
	a_node->sons_end_dummy->next = NULL;
	
	// Binding two dummies together
	a_node->sons_start_dummy->next = a_node->sons_end_dummy;
	a_node->sons_end_dummy->prev = a_node->sons_start_dummy;
	
	return a_node;
}


// Initialisation of the root

tree initialize_root()
{
	return initialize_node(0, NULL);
}


// Adding node

void ADD_NODE(tree node, int* n, tree* array_of_addresses)
{
	list a_list = malloc(sizeof(struct s_list_of_nodes));
	a_list->node = initialize_node(*n,a_list);
	a_list->prev=node->sons_end_dummy->prev;
	a_list->next=node->sons_end_dummy;
	(a_list->prev)->next=a_list;
	node->sons_end_dummy->prev=a_list;
	array_of_addresses[*n]=a_list->node;
	++(*n);
}


// Printing number of the most right child

int RIGHTMOST_CHILD(tree node)
{
	if(node->sons_end_dummy->prev!=node->sons_start_dummy)
	{
		return node->sons_end_dummy->prev->node->value;
	}
	else
	{
		return -1;
	}
}


// Deleting node 

void DELETE_NODE(tree node)
{
	// Checking if it has any sons
	if(node->sons_start_dummy==node->sons_end_dummy->prev)
	{
		if(node->father!=NULL)
		{
			(node->father->prev)->next=node->father->next;
			(node->father->next)->prev=node->father->prev;
		}
	}
	else
	{
		(node->father->prev)->next=node->sons_start_dummy->next;
		(node->sons_start_dummy->next)->prev=node->father->prev;
		(node->father->next)->prev=node->sons_end_dummy->prev;
		(node->sons_end_dummy->prev)->next=node->father->next;
		
	}
	free(node->father);
	free(node->sons_start_dummy);
	free(node->sons_end_dummy);
	free(node);
}


// Deleting subtree

void DELETE_SUBTREE(tree node, int* nodes_counter)
{
	while(node->sons_start_dummy->next!=node->sons_end_dummy)
	{
		--(*nodes_counter);
		DELETE_NODE(node->sons_start_dummy->next->node);
	}
	DELETE_NODE(node);
	--(*nodes_counter);
}


// Spliting node

void SPLIT_NODE(tree father, tree son, int* n,tree* array_of_addresses)
{
	// Adding new son and its father link
	tree new_node = initialize_node(*n,NULL);
	array_of_addresses[(*n)]=new_node;
	++(*n);
	new_node->father = malloc(sizeof(struct s_list_of_nodes));
	new_node->father->node=new_node;
	
	// Rearrangement of pointers
	(son->father->next)->prev=new_node->sons_start_dummy;
	new_node->sons_start_dummy->next=son->father->next;
	new_node->father->next=father->sons_end_dummy;
	new_node->father->prev=son->father;
	father->sons_end_dummy->prev->next=new_node->sons_end_dummy;
	new_node->sons_end_dummy->prev=father->sons_end_dummy->prev;
	son->father->next=new_node->father;
	father->sons_end_dummy->prev=new_node->father;
}