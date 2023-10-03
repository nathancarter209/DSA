// Queue using linked list ?
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}
// *head=NULL;

// struct node * = NULL;
// struct node * = NULL;
#define size 5
int arr[size];
void enqueue();
void dequeue();
void display();
void print();

void enqueue(int x) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    if (front == NULL && rear == NULL) {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
    rear++;
}
/* Dequeue */  //Queue using array
void dequeue() {
    struct node *temp = front;
    if (front == NULL) {
        printf("Queue is Empty\n");
        return;
    }
    if (front == rear) {
        front = rear = NULL;
    }
    else {
        front = front->next;
    }
    free(temp);
    front++;
}
int front() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    return front->data;
}
int underflow()
{
    if (front == NULL)
        return 1;
    else
        return 0;
}

void print() {
    struct node *temp = front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void display (){
    int i;
    if (underflow())
    {
        printf ("Queue is empty\n");
    }
    else
    {
        printf ("Elements in the queue are: ");
        for (i=front; i <= rear; i++)
        {
            printf ("%d ", arr [i]);
        }
        printf ("\n");
    }
}
int main ()
{
    int choice, item;
    do
    {
        printf ("1.Enqueue\n");
        printf ("2.Dequeue\n");
        printf ("3.Display\n");
        printf ("4.Exit\n");
        printf ("Enter your choice: ");
        scanf ("%d", &choice);
        switch (choice)
        {
            case 1:
                printf ("Enter the element to be inserted: ");
                scanf ("%d", &item);
                enqueue (item);
                break;
            case 2:
                dequeue ();
                break;
            case 3:
                display ();
                break;
            case 4:
                exit (1);
            default:
                printf ("Invalid choice\n");
        }
    }
    while (choice != 4);
    return 0;
}


