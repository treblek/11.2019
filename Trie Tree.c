//You should download words_alpha.txt in same directory for test data. It use 230.000K ram for 370.000 words.

#include "stdio.h"
#include "stdlib.h"

#define LENGTH_OF_ALPHABET 26



FILE *fptr;//

typedef struct node
{
	struct node *letter[LENGTH_OF_ALPHABET];
	char *meanOfWord;
}node;
void setRoot(node **root);
void addWord(node *,char*,char*);
void addWord_endOfWord(node*,char*);
void stringCopy(char*,char*);
void printMeanOfWord(node*,char*);
void addTestWords(node*);//Test verisi

int main()
{
	node *root; setRoot(&root);
	addTestWords(root);//Test Verisi
	return -1;
}

void addTestWords(node *root)//
{
		fptr  = fopen("words_alpha.txt","r");
		char str[50];
		
		while(!feof(fptr))
		{

  		 	fscanf(fptr,"%s\n",str);
			addWord(root,str,str);
		}
		printf("Kelimeler eklendi!");
		while(1)
		{
			printf("\nAnlamini ogrenmek istediginiz kelime giriniz.");
			scanf("%s",str);
			printMeanOfWord(root,str);
		}
}

void addWord(node *root,char* inComingWord,char* inComingMean)
{
	if(inComingWord[0] == '\0')
		{
			addWord_endOfWord(root,inComingMean);
			return;
		}
				if(root->letter[(int)inComingWord[0]-(((int)inComingWord[0]>=97)?97:65)] == NULL) 
		{
			setRoot(&root->letter[(int)inComingWord[0]-(((int)inComingWord[0]>=97)?97:65)]);
			addWord(root->letter[(int)inComingWord[0]-(((int)inComingWord[0]>=97)?97:65)],inComingWord+sizeof(char),inComingMean);
		}
			else
				addWord(root->letter[(int)inComingWord[0]-(((int)inComingWord[0]>=97)?97:65)],inComingWord+sizeof(char),inComingMean);
		
} 
void printMeanOfWord(node*root,char*inComingWord)
{
	if(root == NULL)
	{
		printf("kelime bulunamadi!");
		return;
	}
	if(inComingWord[0] == '\0')
	{
		printf("Kelimenin anlami : %s",root->meanOfWord);
		return;
	}
	printMeanOfWord(root->letter[(int)inComingWord[0]-(((int)inComingWord[0]>=97)?97:65)],inComingWord+sizeof(char));
	
}
void addWord_endOfWord(node* root,char* inComingMean)
{
	
		root->meanOfWord = (char*)malloc(sizeof(char)*(stringLength(inComingMean)+1));
		stringCopy(inComingMean, root->meanOfWord);
}
void stringCopy(char*copyArray,char*pasteArray)
{
	if(copyArray == NULL)
	{
		printf("Kopyalanacak dizi bos!"); return;
	}
	pasteArray[0] = copyArray[0];
	
	if(copyArray[0] == '\0')
			return;
		
	stringCopy(copyArray+sizeof(char),pasteArray+sizeof(char));
	
}
int stringLength(char *incomingWord)
{
	if(incomingWord[0] == '\0')
	return 0;
	return 1 +stringLength(incomingWord+sizeof(char));
}
void setRoot(node **root)
{
	(*root) = (node*)malloc(sizeof(node));
	
		int i;
		for(i=0;i<LENGTH_OF_ALPHABET;i++)
			(*root)->letter[i] = NULL;
}
