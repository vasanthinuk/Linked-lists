#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node *prev;
	int data;
	struct node *next;
};

struct node *head;

void insert_begin();
void insert_end();
void insert_specified();
void delete_begin();
void delete_end();
void delete_specified();
void search();
void display();

int main()
{
	int ch;
	printf("Implementation of double Linked list\n");
	while(1)
	{
		printf("1.Insertion at begining\n2.Insertion at end\n3.Insertion at specified location\n4.Deletion at begining\n5.Deletion at end\n6.Deletion at specified location\n7.search\n8.Display\n9.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 : insert_begin();
				 break;
		 	case 2 : insert_end();
				 break;
			case 3 : insert_specified();
				 break;
			case 4 : delete_begin();
				 break;
			case 5 : delete_end();
				 break;
			case 6 : delete_specified();
				 break;
			case 7 : search();
				 break;
			case 8 : display();
				 break;
			case 9 : exit(1);
				 break;
			default : printf("Invalid choice\n");
		}
	}
	return 0;
}

void insert_begin()//inserting of the node at begining of double linked list
{
	int ele;
	struct node *ptr;
	ptr = (struct node *)malloc(sizeof(struct node));
	if(ptr == NULL)
	{
		printf("Doubly linked list is empty\n");
	}
	else
	{
		printf("Enter element into list:");
		scanf("%d", &ele);
		if(head == NULL) //checking whether the head is NULL or not
		{
			
			ptr -> next = NULL;
			ptr -> prev = NULL;
			ptr -> data = ele;
			head = ptr;
		}
		else
		{
			ptr -> data = ele;
			ptr -> prev = NULL;
			ptr -> next = head;
			head -> prev = ptr;
			head = ptr;
		}
		printf("Node is inserted\n");
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
		printf("Double linked list is overflow\n");
	}
	else
	{
		printf("Enter data:");
		scanf("%d",&ele);
		ptr -> data = ele;
		if(head == NULL)
		{
			ptr -> next = NULL;
			ptr -> prev = NULL;
			head = ptr;
		}
		else
		{
			temp = head;
			while(temp -> next != NULL)
			{
				temp = temp -> next;
			}
			temp -> next = ptr;
			ptr -> prev = temp;
			ptr -> next = NULL;
		}
	}
	printf("Node inserted\n");
}

void insert_specified()
{
	struct node *ptr;
	struct node *temp;
	int ele;
	int loc;
	ptr = (struct node*)malloc(sizeof(struct node));
	if(ptr == NULL)
	{
		printf("Linked list is overflow\n");
	}
	else
	{	
		temp = head;
		printf("Enter location:");
		scanf("%d",&loc);
		for(int i = 0; i < loc-1; i++)
		{	
			temp = temp -> next;
			if(temp == NULL)
			{
				printf("The elements are less than %d",loc);
			}
		}
		printf("Enter data:");
		scanf("%d",&ele);
		ptr -> data = ele;
		ptr -> next = temp -> next;
		temp -> next = ptr;
		temp -> next -> prev = ptr;
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
	else if(head -> next == NULL)
	{
		head = NULL;
		free(head);
		printf("Node deleted\n");
	}
	else
	{
		ptr = head;
		head = head -> next;
		head ->prev = NULL;
		free(ptr);
		printf("Node deleted\n");
	}
}

void delete_end()
{
	struct node *ptr;
	if(head == NULL)
	{
		printf("Linked list is overflow\n");
	}
	else if(head -> next == NULL)
	{
		head = NULL;
		free(head);
		printf("Node deleted\n");
	}
	else
	{
		ptr = head;
		while(ptr -> next != NULL)
		{
			ptr = ptr -> next;
		}
		ptr ->prev->next =NULL;
		free(ptr);
		printf("Node deleted\n");
	}
}

void delete_specified()
{
	struct node *ptr;
	struct node *temp;
	int pos;
	int i = 0;
	printf("Enter the element to be deleted:");
	scanf("%d",&pos);
	ptr = head;
	while(i< pos-1)
	{
		ptr = ptr -> next;
		i++;
	}
	if(ptr -> next == NULL)
	{
		printf("Can't delete\n");
	}
	else if(ptr -> next ->next == NULL)
	{
		ptr -> next = NULL;
	}
	else
	{
		temp = ptr ->next;
		ptr -> next = temp -> next;
		temp -> next -> prev = ptr;
		free(temp);
		printf("Node deleted\n");
	}

}

void search()
{
	struct node *ptr;
	int ele;
	int flag;
	int i = 0;
	ptr = head;
	if(ptr == NULL)
	{
		printf("Linked list is empty\n");
	}
	else
	{
		printf("Enter element to be searched:");
		scanf("%d",&ele);
		while(ptr != NULL)
		{
			if(ptr -> data == ele)
			{
				printf("Element found at location %d:",i+1);
				flag = 0;
				break;
			}
			else
			{
				flag = 1;
			}
			i++;
			ptr = ptr -> next;
		}
		if(flag == 1)
		{
			printf("Element not found\n");
		}
	}
}

void display()
{
	struct node *ptr;
	printf("Elements in double linked list are:\n");
	ptr = head;
	while(ptr != NULL)
	{
		printf("%d->",ptr ->data);
		ptr = ptr -> next;
	}
	printf("\n");
}
			

