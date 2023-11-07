#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *head;

void insert_begin();
void insert_end();
void delete_begin();
void delete_end();
void search();
void display();

int main()
{
	int ch;
	printf("Implementation of Circular single linked list\n");
	while(1)
	{
		printf("1.Insertion at begining\n2.Insertion at end\n3.Deletion at begining\n4.Deletion at end\n5.search\n6.Display\n7.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{	
			case 1 : insert_begin();
				 break;
			case 2 : insert_end();
				 break;
			case 3 : delete_begin();
				 break;
			case 4 : delete_end();
				 break;
			case 5 : search();
				 break;
			case 6 : display();
				 break;
			case 7 : exit(1);
				 break;
			default :printf("Invalid choice\n");
		}
	}
	return 0;
}

void insert_begin()
{
	struct node *ptr;
	struct node *temp;
	int ele;
	ptr = (struct node*)malloc(sizeof(struct node));
	if(ptr == NULL)
	{
		printf("Linked list is empty\n");
	}
	else
	{
		printf("Enter data:");
		scanf("%d",&ele);
		ptr -> data = ele;
		if(head == NULL)
		{	
		  	head = ptr;
			ptr -> next = head;
		}
		else
		{
			temp = head;
			while(temp -> next != head)
			{
				temp = temp->next;
			}
			ptr->next = head;
			temp ->next = ptr;
			head = ptr;
		}
		printf("Node inserted\n");
	}
}

void insert_end()
{
	struct node *ptr;
	struct node *temp;
	int ele;
	ptr = (struct node*)malloc(sizeof(struct node));
	if(ptr == NULL)
	{
		printf("Linked list is empty\n");
	}
	else
	{
		printf("Enter data:");
		scanf("%d",&ele);
		ptr ->data = ele;
		if(head == NULL)
		{
			head = ptr;
			ptr -> next = head;
		}
		else
		{
			temp = head;
			while(temp -> next != head)
			{
				temp = temp -> next;
			}
			temp -> next = ptr;
			ptr -> next = head;
		}
		printf("Node inserted\n");
	}
}

void delete_begin()
{
	struct node *ptr;
	if(head == NULL)
	{
		printf("Linked list is empty\n");
	}
	else if(head -> next == head)
	{
		head = NULL;
		free(head);
		printf("Node deleted\n");
	}
	else
	{
		ptr = head;
		while(ptr ->next!= head)
		{
			ptr = ptr -> next;
		}
		ptr -> next = head -> next;
		free(head);
		head = ptr -> next;
		printf("Node deleted\n");
	}
}

void delete_end()
{
	struct node *ptr;
	struct node *temp;
	if(head == NULL)
	{
		printf("Linked list is emoty\n");
	}
	else if(head -> next == head)
	{
		head = NULL;
		free(head);
		printf("Node deleted\n");
	}
	else
	{
		ptr = head;
		while(ptr -> next != head)
		{
			temp = ptr;
			ptr = ptr -> next;
		}
		temp -> next = ptr -> next;
		free(ptr);
		printf("Node deleted\n");
	}
}

void search()
{
	struct node *ptr;
	int ele;
	int i = 0;
	int count = 1;
	ptr = head;
	if(ptr == NULL)
	{
		printf("Linked list is empty\n");
	}
	else
	{
		printf("Enter the item to search:");
		scanf("%d",&ele);
		if(head -> data == ele)
		{
			printf("Element found at location %d:",i+1);
		}
		else
		{
			while(ptr -> next != head)
			{
				if(ptr -> data == ele)
				{
					printf("Item found at location %d:", i+1);
					count = 0;
					break;
				}
				else
				{
					count = 1;
				}
				i++;
				ptr = ptr -> next;
			}
		}
		if(count != 0)
		{
			printf("Item not found\n");
		}
	}
}

void display()
{
	struct node *ptr;
	ptr = head;
	if(head == NULL)
	{
		printf("Linked list is empty\n");
	}
	else
	{
		printf("The elements of linked list are:\n");
		while(ptr -> next != head)
		{
			printf("%d-> ", ptr -> data);
			ptr = ptr -> next;
		}
		printf("%d->\n ", ptr -> data);
	}
}

