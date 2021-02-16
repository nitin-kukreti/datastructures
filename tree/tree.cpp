#include <iostream>
#include "Queue.h"
class tree
{
private:
    /* data */
public:
    node *root;
    tree(/* args */);
    ~tree();
    void Createtree();
    void Preorder(node *p);
    void Postorder(node *p);
    void Inorder(node *p);
    void levelorder(node *p);
    void height(node *root);
};
void tree::Createtree()
{
    node *p, *t;
    int x;
    Queue q(100);
    printf("Eneter root value ");
    scanf("%d", &x);
    root = new node;
    root->data = x;
    root->leftchild = root->rightchild = NULL;
    q.enqueue(root);
    while (!q.isEmpty())
    {
        p = q.dequeue();
        printf("eneter left child of %d ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = new node;
            t->data = x;
            t->leftchild = t->rightchild = NULL;
            p->leftchild = t;
            q.enqueue(t);
        }
        printf("eneter right child of %d ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = new node;
            t->data = x;
            t->leftchild = t->rightchild = NULL;
            p->rightchild = t;
            q.enqueue(t);
        }
    }
}
void tree::Preorder(node *p)
{
    if (p != NULL)
    {
        printf("%d", p->data);
        Preorder(p->leftchild);
        Preorder(p->rightchild);
    }
}
void tree::Postorder(node *p)
{  if (p != NULL)
    {
        
        Postorder(p->leftchild);
        Postorder(p->rightchild);
        printf("%d", p->data);
    }
}
void tree::Inorder(node *p)
{
      if (p != NULL)
    {
        Inorder(p->leftchild);
        printf("%d", p->data);
        Inorder(p->rightchild);
    }
}
void tree::levelorder(node *root)
{
Queue q(100);
printf("%d ",root->data);
q.enqueue(root);
while(!q.isEmpty())
{
root=q.dequeue();
if(root->leftchild)
{
printf("%d ",root->leftchild->data);
q.enqueue(root->leftchild);
}
if(root->rightchild)
{
printf("%d ",root->rightchild->data);
q.enqueue(root->rightchild);
}
}
}
void tree::height(node *root)
{
}

tree::tree(/* args */)
{
    root = NULL;
}

tree::~tree()
{
}

int main()
{
    tree t;
    t.Createtree();
    t.Preorder(t.root);
    printf("\n");
    t.Postorder(t.root);
    printf("\n");
    t.Inorder(t.root);
    printf("\n");
    t.levelorder(t.root);
    return 0;
}
