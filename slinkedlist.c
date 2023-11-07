#include<stdio.h>
#include<stdlib.h>

struct node //linked list node creation
{
	int data;
	struct node *next;
};

void addNode();
void insert_begin();
void insert_end();
void insert_randomlocation();
void deletion_begin();
void deletion_end();
void deletion_location();
void remove_duplicate();
void sortList();
void search();
void minNode();
void display();

struct node *head;
struct node *tail;

int main()
{
	int ch;
	while(1)
	{
		printf("1.Adding nodes to linked list\n2.Insertion at begining:\n3.Display\n4.Insertion at end\n5.Insertion at particular location\n6.Deletion at Begining\n7.Deletion at End\n8.Deletion at position\n9.search for a Element\n10.Remove duplicate Element\n11.Minimum node of linked list\n12.sorting of linked list\n13.Exit\n");
		printf("Enter your choice:");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1 : addNode();
				 break;
			case 2 : insert_begin();
				 break;
			case 3 : display();
			 	 break;
			case 4 : insert_end();
				 break;
			case 5 : insert_randomlocation();
				 break;
			case 6 : deletion_begin();
				 break;
			case 7 : deletion_end();
				 break;
			case 8 : deletion_location();
				 break;
			case 9 : search();
				 break;
			case 10 : remove_duplicate();
				  break;
			case 11 : minNode();
				  break;
			case 12 : sortList();
				  break;
			case 13 : exit(1);
				 break; 
			default : printf("Invalid choice:");
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
	if(ptr == NULL)
	{
		printf("Memory is not allocated");
	}
	if(head == NULL)
	{
		head = ptr;
		tail = ptr;
	}
	else
	{
		tail->next = ptr;
		tail = ptr;
	}
}

void insert_begin()//insertion at the begining of the linked list
{
	struct node *ptr;//creating a pointer
	int item;
	ptr = (struct node*)malloc(sizeof(struct node));//allocating memory to a pointer
	if(ptr == NULL)
	{
		printf("Memory not allocated:");
	}
	else
	{
		printf("Enter value:");
		scanf("%d", &item);
		ptr -> data = item;
		ptr -> next = head;
		head = ptr;
		printf("Node Inserted:\n");
	}
}

void insert_end() //insertion at the end of linked list
{
	struct node *ptr;
	struct node *temp;
	int item;
	ptr = (struct node*)malloc(sizeof(struct node));
	if(ptr == NULL) //checking whether the pointer is empty or not
	{
		printf("overflow\n");
	}
	else
	{	
		printf("Enter value:");
		scanf("%d", &item);
		ptr -> data = item;
		if(head == NULL)
		{	
			ptr -> next = NULL;
			head = ptr;
			printf("Node is inserted");
		}
		else
		{
			temp = head;
			while(temp -> next != NULL)
			{
				temp = temp -> next;
			}
			temp -> next = ptr;
			ptr -> next = NULL;
			printf("Node Inserted at end:\n");
		}
	}
}

void insert_randomlocation()//inserting a element at random location
{
	struct node *ptr;
	struct node *temp;
	int item;
	int loc;
	ptr = (struct node*)malloc(sizeof(struct node));
	if(ptr == NULL)
	{
		printf("Linked list is overflow\n");
	}
	else
	{
		
		printf("Enter value to be inserted:");
		scanf("%d", &item);
		ptr -> data = item;
		printf("Enter the location where you want to insert the node:");
		scanf("%d", &loc);
		temp = head;
		for(int i = 0; i < loc-1; i++)
		{
			temp = temp -> next;
			if(temp == NULL)
			{
				printf("\n can't insert the element\n");
				return;
			}
		}
		ptr -> next = temp -> next;
		temp -> next = ptr;
		printf("Node inserted at particular location\n");
	}
}

void deletion_begin()
{
	struct node *ptr;
	if(head == NULL)
	{
		printf("Linked list is empty\n");
	}
	else
	{
		ptr = head;
		head = ptr->next;
		free(ptr);
		printf("Node deleted from the begining\n");
	}
}

void deletion_end()//delete of the element at last in linked list
{
	struct node *ptr;
	struct node *ptr1;
	if(ptr == NULL)
	{
		printf("Linked list is empty\n");
	}
	else if(head -> next == NULL)
	{
		head = NULL;
		free(head);
		printf("Node of the linked list is deleted\n");
	}
	else
	{
		ptr = head;
		while(ptr -> next != NULL)
		{
			ptr1 = ptr;
			ptr = ptr -> next; 
		}
		ptr1 -> next = NULL;
		free(ptr);
		printf("Last node of the linked list is deleted\n");
	}
}


void deletion_location()
{
	struct node *ptr;
	struct node *ptr1;
	int loc;
	printf("Enter the location of the element to be deleted\n");
	scanf("%d", &loc);
	ptr = head;
	for(int i = 0; i < loc; i++)
	{
		ptr1 = ptr;
		ptr = ptr -> next;
		if(ptr == NULL)
		{
			printf("Element cannot be deleted\n");
		}
	}
	ptr1 -> next = ptr -> next;
	free(ptr);
	printf("Node is deleted based on location\n");
}

void search()
{
	struct node *ptr;
	int item;
	int count;
	int i = 0;
	ptr = head;
	if(ptr == NULL)
	{
		printf("Linked list is empty\n");
	}
	else
	{
		printf("Enter an element to be searched:");
		scanf("%d", &item);
		while(ptr != NULL)
		{
			if(ptr -> data == item)
			{
				printf("Searched element found at location:%d\n",i+1);
				count = 0;
			}
			else
			{
				count = 1;
			}
			i++;
			ptr = ptr -> next;
		}
		if(count == 1)
		{
			printf("Searched element not found\n");
		}
	}
}

void remove_duplicate()
{
	struct node *current = head;
	struct node *index = NULL;
	struct node *temp = NULL;
	if(head == NULL)
	{
		printf("Linked list is empty\n");
	}
	else
	{
		while(current != NULL)
		{
			temp = current;
			index = current -> next;
			while(index != NULL)
			{
				if(current -> data == index-> data)
				{
					temp -> next = index -> next;
				}
				else
				{
					temp = index;
				}
				index = index->next;
			}
			current = current -> next;
		}
	}
}

void minNode()
{
	struct node *current = head;
	int min;
	if(head == NULL)
	{
		printf("Linked list is empty\n");
	}
	else
	{
		min = head->data;
		while(current != NULL)
		{
			if(min > current->data)
			{
				min = current->data;
			}
			current = current->next;
		}
		printf("Minimum value of the node in linked list:%d\n", min);
	}
}

void sortList()
{
	struct node *current = head;
	struct node *index;
	int temp;
	while(current != NULL)
	{
		index = current -> next;
		while(index != NULL)
		{
			if(current -> data < index -> data)
			{
				temp = current -> data;
				current -> data = index -> data;
				index -> data = temp;
			}
			index = index-> next;
		}
		current = current -> next;
	}
}

void display()
{
	struct node *ptr;
	ptr = head;
	if(ptr == NULL)
	{
		printf("No values to be printed\n");
	}
	else
	{	
		printf("Values in single linked list are:\n");
		while(ptr != NULL)
		{
			printf("%d->", ptr -> data);
			ptr = ptr -> next;
		}
		printf("\n");
	}

}
