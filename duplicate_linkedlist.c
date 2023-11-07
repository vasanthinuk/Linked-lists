#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void addNode();
void removeDuplicate();
void display();

int main()
{
	int ch;
	while(1)
	{
		printf("1.Adding a node to linked list\n2.removing duplicate element\n3.display\n4.Exit\n");
		printf("Enter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 : addNode();
				 break;
			case 2 : removeDuplicate();
				 break;
			case 3 : display();
				 break;
			case 4 : exit(1);
				 break;
			default :printf("Invalid Choice");
		}
	}
	return 0;
}

void addNode()
{
	int item;
	struct node *ptr;
	ptr = (struct node*)malloc(sizeof(struct node));
	printf("Enter data:");
	scanf("%d", &item);
	ptr -> data = item;
	ptr -> next = NULL;
	if(ptr ==  NULL)
	{
		printf("Memory not allocated\n");
	}
	if(head == NULL)
	{
		head = ptr;
		tail = ptr;
	}
	else
	{
		tail -> next = ptr;
		tail = ptr;
	}
}

void removeDuplicate()
{
	struct node *current = head;
	struct node *index = NULL;
	struct node *temp = NULL;
	if(head == NULL)
	{
		return;
	}
	else
	{
		while(current != NULL)
		{
		   	temp = current;
			index = current -> next;
			while(index != NULL)
			{
				if(current -> data == index -> data)
				{
					temp -> next = index -> next;
				}
				else
				{
					temp = index;
				}
				index = index -> next;
			}
			current = current -> next;
		}
	}
}

void display()
{
	struct node *current = head;
	if(head == NULL)
	{
		printf("Linked list is emplty\n");
	}
	while(current != NULL)
	{
		printf("%d ->", current -> data);
		current = current -> next;
	}
	printf("\n");
}
