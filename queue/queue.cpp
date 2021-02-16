#include<iostream>


using namespace std;
struct queue
{
  int data;
  queue *next;  
}*frist,*last;

void push(int data){
    queue *p=new queue;
    p->data=data;
    p->next=NULL;

    if(!frist){
       last=frist=p;
    }else
    {
        last->next=p;
        last=p;
    }
    
}

int pop(){
    if(!frist){
       printf("queue is empty");
       return 0;
    }
   queue *q=frist;
    frist=frist->next;
    cout<<"poped element"<<q->data<<endl; 
    delete q;
    return 1;
}

void display(){
    queue *node=frist;
    while(node){
        cout<<node->data<<endl;
        node=node->next;
    }
}
int main()
{
    int ch;
     while (true)
     {
         cout<<"1 for pushing element in queue\n";
         cout<<"2 for pop element from queue\n";
         cout<<"3 for display element of queue\n";
         cout<<"any number except 1,2,3 to quit\n";
         cin>>ch;
         cout<<"----------\n";
         switch (ch)
         {
         case 1:
             int data;
             cout<<"enter data\n";
             cin>>data;
             push(data);
             break;
         case 2:
             pop();
             break;
         case 3:
             display();
             break;
         default:
         exit(1);
             break;
         }
     }
     
    return 0;
}
