/* Name:Chayathorn Terataninan
 * ID: 6280945
 */

#include<stdio.h>
#include<stdlib.h>
#include"sortedlist.h"
// Feels free to include anything here if you need to
//
//
struct linked_list
{
    int number;
    struct linked_list *next;
};

typedef struct linked_list node;
node *head=NULL, *last=NULL;

void create_linked_list();
void print_linked_list();
void insert_at_last(int value);
void insert_at_first(int value);
void insert_after(int key, int value);
void delete_item(int value);
void search_item(int value);

void create_linked_list()
{
    int val;

    while(1)
    {
        printf("Input a number. (Enter -1 to exit)\n");

        scanf("%d", &val);

        if(val==-1)
            break;

        insert(val);
    }

}

int search(int num)
{
    node *searchNode = head;
    int flag = 0;

    while(searchNode!=NULL)
    {
        if(searchNode->number==value)
        {
            printf("%d is present in this list. Memory address is %d\n", value, searchNode);
            flag = 1;
            break;
        }
        else
            searchNode = searchNode->next;
    }

    if(flag==0)
        printf("Item not found\n");

}

void insert(int num)
{
    node *temp_node;
    temp_node = (node *) malloc(sizeof(node));

    temp_node->number=value;
    temp_node->next=NULL;

    //For the 1st element
    if(head==NULL)
    {
        head=temp_node;
        last=temp_node;
    }
    else
    {
        last->next=temp_node;
        last=temp_node;
    }
}

int delete(int num)
{
   node *myNode = head, *previous=NULL;
    int flag = 0;

    while(myNode!=NULL)
    {
        if(myNode->number==value)
        {
            if(previous==NULL)
                head = myNode->next;
            else
                previous->next = myNode->next;

            printf("%d is deleted from list\n", value);

            flag = 1;
            free(myNode); //need to free up the memory to prevent memory leak
            break;
        }

        previous = myNode;
        myNode = myNode->next;
    }

    if(flag==0)
        printf("Key not found!\n");
}

void print()
{
   printf("\nYour full linked list is\n");

    node *myList;
    myList = head;

    while(myList!=NULL)
    {
        printf("%d ", myList->number);

        myList = myList->next;
    }
    puts("");
}

int main()
{
   int key, value;

   //Create a linked list
   printf("Create Linked List\n");
   create_linked_list();
   print();


   //Insert value at last position to existing Linked List
   printf("\nInsert new item at last\n");
   scanf("%d", &value);
   insert(value);
   print();


   //Insert value at first position to existing Linked List
   printf("\nInsert new item at first\n");
   scanf("%d", &value);
   insert(value);
   print();

   //Search an item from Linked List
   printf("\nEnter an item to search it from List\n");
   scanf("%d", &value);
   search(value);


    //Delete value from List
    printf("\nEnter a value, which you want to delete from list\n");
    scanf("%d", &value);
    delete(value);
    print();


    return 0;	
}

