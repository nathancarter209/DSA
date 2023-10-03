//stack using doubly link list
#include<stdio.h>   
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head = NULL;
struct node *tail = NULL;
void push ()
{
    int item;
    struct node *ptr = (struct node *) malloc (sizeof (struct node));
    if (ptr == NULL)
    {
        printf ("Overflow\n");
    }
    else
    {
        printf ("Enter the element to be inserted: ");
        scanf ("%d", &item);
        ptr->data = item;
        if (head == NULL)
        {
            ptr->next = NULL;
            ptr->prev = NULL;
            head = ptr;
            tail = ptr;
        }
        else
        {
            ptr->next = head;
            ptr->prev = NULL;
            head->prev = ptr;
            head = ptr;
        }
    }
}
void pop ()
{
    struct node *ptr = head;
    if (head == NULL)
    {
        printf ("Underflow\n");
    }
    else
    {
        printf ("The deleted element is %d\n", ptr->data);
        head = head->next;
        head->prev = NULL;
        free (ptr);
    }
}
void display ()
{
    struct node *ptr = head;
    if (head == NULL)
    {
        printf ("Underflow\n");
    }
    else
    {
        
        while (ptr != NULL)
        {
            printf ("%d\n", ptr->data);
            ptr = ptr->next;
        }
    }
}
int main ()
{
    int choice;
    while (1)
    {
        printf ("---MENU---\n");
        printf ("1.Push\n");
        printf ("2.Pop\n");
        printf ("3.Display\n");
        printf ("4.Exit\n");
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
