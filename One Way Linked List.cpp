#include "stdio.h"
#include "stdlib.h"
#include "stack"
using namespace std;
typedef struct node{
	int number;
	struct node *next;
}node;


void ekle(node**,int);//
void yazdir(node*);//
int say(node*);//
void siraliEkle(node**,int);//
void sil(node**,int);//
void tersCevir(node**);//

int main()
{
	node *root = NULL;
	return -1;
}
void tersCevir(node** root)
{
	if(*root == NULL)
	{
		printf("Liste bos!");
		return;
	}
 	
	node *iter=*root,*newRoot = NULL,*temp;
	stack <int> a;
	while(iter->next != NULL)	
	{
		a.push(iter->number);
		iter = iter->next;
	}
	a.push(iter->number);
	while(!a.empty())
	{
		ekle(&newRoot,a.top());
		a.pop();
	}
	iter = *root;
	*root = newRoot;
	free(iter);
}
void sil(node** root,int number)
{
	if(*root == NULL)
	{
		printf("Liste bos!");
		return;
	}
	if((*root)->number == number)
	{
		node *temp;
		temp = *root;
		*root = (*root)->next;
		free(temp);
		return;
	}
	node *iter;
	iter = *root;
	while(iter->next->number != number && iter->next->next != NULL)
	iter = iter->next;
	
	if(iter->next->number != number)
	{
		printf("Sayi bulunmadi!");
		return;
	}
	node *temp;
	temp = iter->next;
	if(iter->next->next == NULL)
	{
		iter->next = NULL;
		free(temp);
	}
	else
	{
		iter->next = iter->next->next;
		free(temp);
	}
	
}

void ekle(node** root,int number)
{
	node *iter;
	iter = *root;
	if(*root == NULL)
	{
		*root = (node*)malloc(sizeof(node));
		(*root)->next = NULL;
		(*root)->number = number;
		return;
	}
	while(iter->next != NULL)
	iter = iter->next;
	iter->next = (node*)malloc(sizeof(node));
	iter->next->number = number;
	iter->next->next = NULL;
}

void siraliEkle(node** root,int number)
{
	if(*root == NULL)
	{
		*root = (node*)malloc(sizeof(node));
		(*root)->number = number;
		(*root)->next = NULL;
		return;
	}
	if((*root)->number >= number)
	{
	    node *temp;
	    temp = (node*)malloc(sizeof(node));
	    temp->number = number;
	    temp->next = *root;
	    *root = temp;
	    return;
	}
	
	
	node *iter = *root;
	while(iter->next != NULL && iter->next->number < number)
	iter = iter->next;
	
	if(iter->next == NULL)
	{
		iter->next = (node*)malloc(sizeof(node));
		iter->next->number = number;
		iter->next->next = NULL;
		return;
	}
   else
   {
   	node *temp;
   	temp = (node*)malloc(sizeof(node));
    temp->number = number;
    temp->next = iter->next;
    iter->next = temp;
   }
	
	
}

int say(node* root)
{
	if(root == NULL)
	return 0;
	else
		return say(root->next)+1;
}

void yazdir(node* root)
{
	if(root == NULL)
	{
		printf("Liste bos!");
		return;
	}
	while(root->next != NULL)
	{
		printf("%d\n",root->number);
		root=root->next;
	}
	printf("%d",root->number);
}
