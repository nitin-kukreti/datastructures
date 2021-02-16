#include<stdio.h>
#ifndef Queue_h
#define Queue_h
class node{
public:
node *leftchild;
int data;
node *rightchild;
~node(){
    delete this;
}
};

class Queue
{
private:
    int front;
    int rear;
    int size;
    node **Q;

public:
    Queue()
    {
        front = rear = -1;
        size = 10;
        Q = new node*[size];
    }
    Queue(int size)
    {
        front = rear = -1;
        this->size = size;
        Q = new node*[this->size];
    }
    void enqueue(node *x);
    node* dequeue();
    void Display();
    int isEmpty();
};
int Queue::isEmpty(){
    return rear==front;
}
void Queue::enqueue(node *x)
{
    if (rear == size - 1)
        printf("Queue Full\n");
    else
    {
        rear++;
        Q[rear] = x;
    }
}
node* Queue::dequeue()
{
    node* x = NULL;
    if (front == rear)
        printf("Queue is Empty\n");
    else
    {
        x = Q[front + 1];
        front++;
    }
    return x;
}
void Queue::Display()
{
    for (int i = front + 1; i <= rear; i++)
        printf("%d ", Q[i]);
    printf("\n");
}

#endif /* queue_h */
