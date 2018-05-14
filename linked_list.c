// A complete working C program to demonstrate all insertion methods
// on Linked List
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

void append(struct Node **head, int new_data)
{
    // define new node
    struct Node * new_node = (struct Node *)malloc(sizeof(struct Node));

    //assign data and make the node point to Null (as it's the last one)
    new_node->data = new_data;
    new_node->next = NULL;

    //check if there is any nodes before it, and if not make it the first :)
    if(*head == NULL){
        *head = new_node;
        return;
    }

    //define pointer for the last node
    struct Node * last = *head;

    //looping until it's the last one
    while(last->next != NULL)
    {
        last = last->next;
    }

    //make the new node we created above the last node in the linked list
    last->next = new_node;
}

//add node at the end of an existing list
void push(struct Node ** head, int new_data)
{
    //create the new node
    struct Node * new_node = malloc(sizeof(struct Node));

    //assign the data and the next node of the new node we created (assign the first node as next for current)
    new_node->data = new_data;
    new_node->next = *head;

    //assign the address of current new node to the pointer of linked list head
    *head = new_node;
}

void insert_After(struct Node * prev_node, int new_data)
{
    if(prev_node == NULL){
        printf("There is an Error, the previos node cann't point to Null!\n");
        return;
    }
    struct Node * new_node = malloc(sizeof(struct Node));

    new_node->data = new_data;
    new_node->next = prev_node->next;

    prev_node->next = new_node;
}


// This function prints contents of linked list starting from head
void printList(struct Node *node)
{
  while (node != NULL)
  {
     printf(" %d ", node->data);
     node = node->next;
  }
}



int main()
{
    int i;
    struct Node * head_ref = NULL;

    for (i=0; i<5 ; i++){
        append(&head_ref, i);
    }

    push(&head_ref, -1);
    push(&head_ref, -2);

    insert_After(head_ref->next, 8);
    printList(head_ref);

    return 0;
}
