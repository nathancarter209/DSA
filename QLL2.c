// queue using linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*front=NULL,*rear=NULL;
void enqueue(int x){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;
    if(front==NULL && rear==NULL){
        front=rear=temp;
        return;
    }
    rear->next=temp;
    rear=temp;
}
void dequeue(){
    struct node *temp=front;
    if(front==NULL){
        printf("Queue is Empty\n");
        return;
    }
    if(front==rear){
        front=rear=NULL;
    }
    else{
        front=front->next;
    }
    free(temp);
}
int Front(){
    if(front==NULL){
        printf("Queue is empty\n");
        return -1;
    }
    return front->data;
}
int underflow()
{
    if(front==NULL)
        return 1;
    else
        return 0;
}
int overflow()
{
    if(rear==NULL)
        return 1;
    else
        return 0;
}
void display(){
    struct node *temp=front;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void print(){
    struct node *temp=front;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main(){
    int n;
    printf("Enter the number of elements to be inserted in the queue\n");
    scanf("%d",&n);
    printf("Enter the elements to be inserted in the queue\n");
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        enqueue(x);
    }
    printf("The elements in the queue are\n");
    print();
    printf("The front element in the queue is %d\n",Front());
    dequeue();
    printf("The elements in the queue after dequeue operation are\n");
    print();
    printf("The front element in the queue is %d\n",Front());
    return 0;
}
