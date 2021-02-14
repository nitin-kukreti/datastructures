#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(/* args */);
    ~node();
};
class linklist
{
private:
    node *frist, *last;
    int size;
    /* data */
public:
    linklist(int x);
    ~linklist();
    void deletenode(int index);
    friend istream &operator>>(istream &is, linklist &ll);
    friend ostream &operator<<(ostream &os, linklist &ll);
    int getsize(){
        return size;
    }
};
istream &operator>>(istream &is, linklist &ll)
{
    node *p = new node;
    printf("enter data : ");
    cin>>p->data;
    if(ll.frist==ll.last==NULL){
        ll.frist=ll.last=p;
        ll.size++;
    }else{
    ll.last->next = p;
    ll.last = p;
    ll.size++;}
    return is;
}

ostream &operator<<(ostream &os, linklist &ll){
   node *p=ll.frist;
   while (p!=NULL)
   {
       cout<<p->data<<endl;
       p=p->next;
   }
   return os;
}
linklist::linklist(int x=0)
{
    frist = new node;
    frist->data=x;
    last = frist;
    size=1;
}

linklist::~linklist()
{
    delete frist;
}

node::node()
{
    next = NULL;
}

node::~node()
{
    delete next;
}

void linklist::deletenode(int index){
    node *n,*q;
    n=frist;
    if (index < 1 || index > size)
    {
        printf("invalid");
    }
    else
    {
        if (index == 1)
        {
            frist = frist->next;
            free(n);
            size--;
        }
        else if (index == size)
        {
            int x = size;
            while (x - 2)
            {
                x--;
                n = n->next;
            }
            last = n;
            free(n->next);
            last->next=NULL;
            size--;
        }
        else
        {
            int x = index;
            while (x - 2)
            {
                x--;
                n = n->next;
            }
            q = n->next;
            n->next=q->next;
            free(q); 
            size--;
        }
    }
}

int main()
{
    cout<<"enter frist value of linked list\n";
    int val,ch;
    cin>>val;
    linklist ll(val);
    while (true)
    {
        cout<<"current length of linked list : "<<ll.getsize()<<endl;

         cout<<"\nchoose among this\n";
    cout<<"1 for append value in a linkedlist\n";
    cout<<"2 for remove value from the linkedlist\n";
    cout<<"3 for display linkedlist elements\n";  
    cin>>ch;
        switch (ch)
        {
        case 1:
           cin>>ll;
            break;
        
        case 2:
          cout<<"enter index u want to delete\n";
          int index;
          cin>>index;
           ll.deletenode(index);
           break;
        case 3:
        cout<<"\n-------\n";
        cout<<ll;
        break;
        default:
            exit(1);
            break;
        }
    }
  
    return 0;
}
