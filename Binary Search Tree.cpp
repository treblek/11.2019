#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

struct n
{
int number;
struct n *left;
struct n *right;	
};
typedef n node;

void elemanEkle(node **,int );
void elemanEkle_nullValue(node **root,int number);
int enBuyukEleman(node *);
int enKucukEleman(node *);
void yazdir(node *);
bool bul(node *,int number);
void sil(node**,int );

int main()
{
	node *root = NULL;
	elemanEkle(&root,7);
	sil(&root,7);
	yazdir(root);
	return -1;
}
void sil(node **root,int number)
{
	if(*root == NULL)
	return;
	if((*root)->number == number)
	if((*root)->left == NULL && (*root)->right == NULL)
	return;
	if((*root)->right != NULL)
	{
		(*root)->number = enKucukEleman((*root)->right);
		sil(&(*root)->right, enKucukEleman((*root)->right));
	}
	(*root)->number = enBuyukEleman((*root)->left);
	sil(&(*root)->left, enBuyukEleman((*root)->left));
	if((*root)->number < number)
	sil(&(*root)->right,number);
	sil(&(*root)->left, number);
}

void yazdir(node *root)
{
	if(root == NULL)
	return;
	yazdir(root->left);
	printf("%d ",root->number);
	yazdir(root->right);
}
bool bul(node *root,int number)
{
	if(root == NULL)
	return false;
	if(root->number == number )return true;
	
	if(root->number > number)
	return bul(root->left,number);
	else
	return bul(root->right,number);
}
int enBuyukEleman(node *root)
{
	if(root == NULL)
	{
		printf("Agac bos!");
	 	return -1;
	}
	while(root->right != NULL)
	root = root->right;
	return root->number;
}
int enKucukEleman(node *root)
{
	if(root == NULL)
	{
		printf("Agac bos!");
	 	return -1;
	}
	while(root->left != NULL)
	root = root->left;
	return root->number;
}
void elemanEkle(node **root,int number)
{
	if(*root == NULL)
	elemanEkle_nullValue(root,number);
	else if((*root)->number < number)
	elemanEkle(&(*root)->right,number);
	else
	elemanEkle(&(*root)->left,number);
}
void elemanEkle_nullValue(node **root,int number)
{
	*root = (node*)malloc(sizeof(node));
	(*root)->left = NULL;
	(*root)->right = NULL;
	(*root)->number = number;
}
