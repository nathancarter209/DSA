//stack using array
#include<stdio.h>
#include<stdlib.h>
#define size 10
int overflow ();
int underflow ();
void push ();
void pop ();
void display ();
int arr [size];
int top = -1 ;

int overflow ()
{
    if (top == size - 1)
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
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push ()
{
    int item;
    if (overflow ())
    {
        printf ("Stack is full\n");
    }
    else
    {
        printf ("Enter the element to be inserted: ");
        scanf ("%d", &item);
        top = top + 1;
        arr [top] = item;
    }
}

void pop ()
{
    if (underflow ())
    {
        printf ("Stack is empty\n");
    }
    else
    {
        printf ("The deleted element is %d\n", arr [top]);
        top = top - 1;
    }
}

void display ()
{
    int i;
    if (underflow ())
    {
        printf ("Stack is empty\n");
    }
    else
    {
        printf ("Elements in the stack are: ");
        for (i=top; i>=0; i--)
        {
            printf ("%d ", arr [i]);
        }
        printf ("\n");
    }
}

int main ()
{
    int choice;
    while (1)
    {
        printf ("---MENU---\n");
        printf ("1. Push\n");
        printf ("2. Pop\n");
        printf ("3. Display\n");
        printf ("4. Exit\n");
        printf ("Enter your choice: ");
        scanf ("%d", &choice);
        switch (choice)
        {
            case 1:
                push ();
                break;
            case 2:
                pop ();
                break;
            case 3:
                display ();
                break;
            case 4:
                exit (0);
            default:
                printf ("Invalid choice\n");
        }
    }
}
