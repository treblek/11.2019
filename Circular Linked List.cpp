#include "stdio.h"
#include "stdlib.h"
#include "stack"
using namespace std;

typedef struct node{
	int number;
	struct node *next;
}node;

//Should send to function &root that Contain double * functions
void ekle(node**,int);//add
void yazdir(node*);//print
int say(node*);//how many
int say_2(node*,node*);//sub func how many
void siraliEkle(node**,int);//add by in order
void sil(node**,int);//delete
void tersCevir(node**);//reverse

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
	while(iter->next != *root)	
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
	node *iter = *root,*temp;
	if((*root)->number == number)
	{
		if((*root)->next == *root)
		{
			free(*root);
			*root = NULL;
			return;
		}
		while(iter->next != *root)
			iter = iter->next;
			temp = iter->next;
		iter->next = iter->next->next;
		*root = iter->next;
		free(temp);
		return;
	}
	while(iter->next != *root&&iter->next->number != number)
	iter = iter->next;
	
	if(iter->next->number != number)
		printf("Sayi bulunmadi!");
	else
	{
		temp = iter->next;
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
		(*root)->next = *root;
		(*root)->number = number;
		return;
	}
	while(iter->next != *root)
	iter = iter->next;
	iter->next = (node*)malloc(sizeof(node));
	iter->next->number = number;
	iter->next->next = *root;
}

void siraliEkle(node** root,int number)
{
	if(*root == NULL)
	{
		*root = (node*)malloc(sizeof(node));
		(*root)->number = number;
		(*root)->next = *root;
		return;
	}
	node *temp=(node*)malloc(sizeof(node)),*iter=*root;
	temp->number = number;
	if((*root)->number > number)
	{
		temp->next = *root;
		while(iter->next != *root)
		iter = iter->next;
		iter->next = temp;
		*root = temp;
	}
	else
	{
		while(iter->next->number < number && iter->next != *root)
		iter = iter->next;
		
		if(iter->next == *root)
		{
			temp->next = *root;
			iter->next = temp;
		}
		else
		{
			temp->next = iter->next;
			iter->next = temp;
		}
	}
}

int say(node* root)
{
	if(root == NULL)return 0;
	return say_2(root->next,root);
}
int say_2(node* root,node* originalRoot)
{
	if(root == originalRoot)
	return 1;
	else
		return say_2(root->next,originalRoot)+1;
}
void yazdir(node* root)
{
	if(root == NULL)
	{
		printf("\nListe bos!\n");
		return;
	}
	node *iter = root;
	printf("\n");
	while(iter->next != root)
	{
		printf("%d\n",iter->number);
		iter=iter->next;
	}
	printf("%d\n",iter->number);
}
