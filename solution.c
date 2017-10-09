#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "tree.h"

int main(int argc, char **argv)
{
	// Initialisation
	int n=1;
	int nodes_counter=1;
	tree* array_of_addresses = malloc(sizeof(tree)*1048581);
	tree root = initialize_root();
	array_of_addresses[0]=root;
	char command[20];
	int node1, node2;

	// Getting flag
	char ifflag=0;
	if(argc>2)
	{
		printf("ERROR\n");
		return 1;
	}
	if(argc==2)
	{
		if(strcmp(argv[1],"-v")==0)
		{
			ifflag=1;
		}
		else
		{
			printf("ERROR\n");
			return 1;
		}
	}

	// Main loop
	while(scanf("%s",command)!=EOF)
	{
		// choice of the instruction
		if(strcmp(command,"ADD_NODE")==0)
		{
			scanf("%d",&node1);
			ADD_NODE(array_of_addresses[node1],&n,array_of_addresses);
			printf("OK\n");
			++nodes_counter;
		}
		if(strcmp(command,"RIGHTMOST_CHILD")==0)
		{
			scanf("%d",&node1);
			printf("%d\n",RIGHTMOST_CHILD(array_of_addresses[node1]));
		}
		if(strcmp(command,"DELETE_NODE")==0)
		{
			scanf("%d",&node1);
			DELETE_NODE(array_of_addresses[node1]);
			printf("OK\n");
			--nodes_counter;
		}
		if(strcmp(command,"DELETE_SUBTREE")==0)
		{
			scanf("%d",&node1);
			DELETE_SUBTREE(array_of_addresses[node1],&nodes_counter);
			printf("OK\n");
		}
		if(strcmp(command,"SPLIT_NODE")==0)
		{
			scanf("%d%d",&node1,&node2);
			SPLIT_NODE(array_of_addresses[node1],array_of_addresses[node2],&n, array_of_addresses);
			printf("OK\n");
			++nodes_counter;
		}
		if(ifflag)
		{
			fprintf(stderr,"NODES: %d\n",nodes_counter);
		}
	}

	// Freeing memory
	DELETE_SUBTREE(root,&nodes_counter);
	free(array_of_addresses);
	
	return 0;
}