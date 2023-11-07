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
			
