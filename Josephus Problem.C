#include "stdio.h"
#include "stdlib.h"

#define NUMBEROFSOLDIERS 5
const N = 3;

typedef struct Soldiers{
	char soldier;
	struct Soldiers *next;
}Soldiers;


void setSoldiers(Soldiers **);
void solveTheProblem(Soldiers **);
void numberOfMember(Soldiers *);
void deleteTheMember(Soldiers **);
int main()
{
	Soldiers *root = NULL; setSoldiers(&root);
	solveTheProblem(&root);
	return -1;
}
void solveTheProblem(Soldiers **root)
{
	int i,j,randomNumber = rand()%NUMBEROFSOLDIERS;
	printf("Start with %d. member\n",randomNumber+1);
	for(i=0;i<randomNumber;i++)
		*root = (*root)->next;
		
	for(i=0;i<NUMBEROFSOLDIERS-1;i++)
	{
		
		for(j=0;j<N-2;j++)
			*root = (*root)->next;
		deleteTheMember(root);
	}
	printf("The soldier who will go take help is %c",(*root)->soldier);
}
void deleteTheMember(Soldiers **root)
{
	Soldiers *temp = (Soldiers*)malloc(sizeof(Soldiers));
	temp = (*root)->next;
	(*root)->next = (*root)->next->next;
	(*root) = (*root)->next;
	free(temp);
	
}
void setSoldiers(Soldiers **root)
{
	if(*root == NULL)
	{
		(*root) = (Soldiers*)malloc(sizeof(Soldiers*));
		Soldiers *iter = *root;
		iter->soldier = (char)(65);
		int i;
		for(i=0;i<NUMBEROFSOLDIERS-1;i++)
		{
			iter->next = (Soldiers*)malloc(sizeof(Soldiers*));
			iter = iter->next;
			iter->soldier = (char)(65+1+i);
			iter->next = NULL;
		}
		iter->next = *root;
	}
	else
		printf("The node isn't empty. Please send a empty node!");
}
