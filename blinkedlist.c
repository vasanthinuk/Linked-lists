#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node
{
	bool data;
	struct Node *next;
};

struct Node *newNode(bool);
int decimalValue(struct Node *);

int main()
{
	struct Node *head;
	int res;
	head = newNode(1);
	head -> next = newNode(0);
	head ->next->next = newNode(1);
	res = decimalValue(head);
	printf("The decimal value is:%d\n",res);
	return 0;
}

struct Node *newNode(bool data)
{
	struct Node *temp;
	temp = (struct Node*)malloc(sizeof(struct Node));
	temp -> data = data;
	temp -> next = NULL;
	return temp;
}

int decimalValue(struct Node *head)
{
	int res = 0;
	while(head != NULL)
	{
		res = (res <<1) + head-> data;
		head = head -> next;
	}
	return res;
}



