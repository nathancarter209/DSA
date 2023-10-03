//Queue using array. 

#include<stdio.h>
#define size 10
#define False = 0
#define True = 1
void enqueue ();
void dequeue ();
void display ();
int overflow ();
int underflow ();
int arr [size];
int front = -1 ;
int rear = -1 ;

//functions
int overflow ()
{
    if (rear == size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int underflow ()
{
    if (front == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue()
{
    int item;
    if (overflow())
    {
        printf ("Queue is full\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        printf ("Enter the element to be inserted: ");
        scanf ("%d", &item);
        rear = rear + 1;
        arr [rear] = item;
    }
}

void dequeue ()
{
    if (underflow())
    {
        printf ("Queue is empty\n");
    }
    else
    {
        printf ("The deleted element is %d\n", arr [front]);
        front = front + 1;
    }
}

void display ()
{
    int i;
    if (underflow())
    {
        printf ("Queue is empty\n");
    }
    else
    {
        printf ("The elements in the queue are: ");
        for (i = front; i <= rear; i++)
        {
            printf ("%d ", arr [i]);
        }
        printf ("\n");
    }
}

// main
int main ()
{
    int choice;
    while (1)
    {
        printf ("xxx MENU xxx\n");
        printf ("1. Enqueue\n");
        printf ("2. Dequeue\n");
        printf ("3. Display\n");
        printf ("4. Exit\n");
        printf ("Enter your choice: ");
        scanf ("%d", &choice);
        switch (choice)
        {
            case 1:
                enqueue ();
                break;
            case 2:
                dequeue ();
                break;
            case 3:
                display ();
                break;
            case 4:
                return 0;
            default:
                printf ("Invalid choice\n");
        }
    }
}