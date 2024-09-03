//C program to develop a game of Hangman

#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct node{
	char letter;
	struct node *next;
}node;

node *create(char letter){
	node *newnode = (node*)malloc(sizeof(node));
	newnode->letter = letter;
	newnode->next = NULL;
	return newnode;
}

void insert(node **head, char letter){
	node *newnode = create(letter);
	if (*head == NULL)
	{
		*head = newnode;
	}
	else{
		node *temp = *head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newnode;
	}
}

void delete(node **head, char letter){
	node *temp = *head;
	node *prev = NULL;
	while(temp != NULL && temp->letter != letter){
		prev = temp;
		temp = temp->next;
	}
	if(temp == NULL){
		return;
	}
	if (prev == NULL)
	{
		*head = temp->next;
	}
	else{
		prev->next = temp->next;
	}
	free(temp);
}

void print(node *head){
	while(head != NULL){
		printf("%c ", head->letter);
		head = head->next;
	}
	printf("\n");
}

void game(node *word){
	node *guess = NULL;
	char letter;
	while(word != NULL){
		printf("guess the word: \n");
		scanf("%c", &letter);
		node *temp = word;
		while(temp != NULL){
			if (temp->letter == letter)
			{
				insert(&guess, letter);
				delete(&word, letter);
				break;
			}
			temp = temp->next;
		}
		print(guess);
	}
	printf("correct guess\n");
}

int main(){
	node *word = NULL;
	char str[100];
	printf("enter a word\n");
	scanf("%s", str);
	for (int i = 0; i < strlen(str); i++)
	{
		insert(&word, str[i]);
	}
	game(word);
	return 0;
}