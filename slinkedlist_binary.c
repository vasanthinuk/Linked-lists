#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
	bool data;
	struct node *next;
};

void addNode();
int decimalValue();
void display();

struct node *head;
struct node *tail;

int main()
{
	int ch;
	while(1)
	{
		printf("1.Adding nodes\n2.binary to decimal\n3.Display\n4.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 :addNode();
				break;
			case 2 :decimalValue();
				break;
			case 3 :display();
				break;
			case 4 :exit(1);
			  	break;
			default :printf("Invalid choice");
		}
	}
	return 0;
}

void addNode()
{
	struct node *ptr;
	bool item;
	ptr = (struct node*)malloc(sizeof(struct node));
	printf("Enter data:");
	scanf("%d",&item);
	ptr -> data = item;
	ptr -> next = NULL;
	if(head == NULL)
	{	
		head = ptr;
		tail = ptr;
	}
	else
	{
		tail->next=ptr;
		tail = ptr;
	}
}

int decimalValue()
{
	struct node *ptr;
	int res = 0;
	ptr = head;
	while(ptr != NULL)
	{
		res = (res << 1) + ptr -> data;
		ptr = ptr -> next;
	}
	return res;
}

void display()
{
	struct node* current = head;
	if(head == NULL)
	{
		printf("Linked list is empty:");
	}
	while(current != NULL)
	{
		printf("%d -> ", current -> data);
		current = current -> next;
	}
	printf("\n");
}

