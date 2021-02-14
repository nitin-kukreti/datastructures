#include<iostream>
using namespace std;

class node
{
private:
    /* data */
public:
    int data;
    node *previous,*next;
    node(/* args */);
    ~node();
};

node::node(/* args */)
{
    previous=next=NULL;
}

node::~node()
{
    delete next;
    delete previous;
}


class doublelinkedlist
{
private:
    /* data */
    node *frist,*last;
    int size;
public:
    doublelinkedlist(int x);
    ~doublelinkedlist();
    friend istream &operator>>(istream &is,doublelinkedlist &dll);
    friend ostream &operator<<(ostream &os,doublelinkedlist &dll);
};
istream &operator>>(istream &is,doublelinkedlist &dll){
    node *p=new node;
    printf("enter data : ");
    cin>>p->data;
    if(!dll.frist){
        dll.frist=dll.last=p;
        dll.size++;
    }else
    {
        dll.last->next=p;
        p->previous=dll.last;
        dll.last=p;
        dll.size++;
    }
    return is;
    
}

doublelinkedlist::doublelinkedlist(int x=0)
{
    frist = new node;
    frist->data=x;
    last = frist;
    size=1;
}

doublelinkedlist::~doublelinkedlist()
{
    delete frist;
    delete last;
}

ostream &operator<<(ostream &os, doublelinkedlist &dll){
   node *p=dll.frist;
   while (p!=NULL)
   {
       cout<<p->data<<endl;
       p=p->next;
   }
   return os;
}


int main(int argc, char const *argv[])
{
    doublelinkedlist dll(5);
    cin>>dll;
    cin>>dll;
    cout<<dll;
    
    return 0;
}

