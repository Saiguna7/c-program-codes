#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
int data;
struct node *lchild;
struct node *rchild;
};
struct node *create(int x)
{
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));
    t->data=x;
    t->lchild=t->rchild=NULL;
    return t;
}
struct node *insert(struct node *root,int x)
{
if(root==NULL)
{
return create(x);
}
if(root->data<=x)
{
root->lchild=insert(root->lchild,x);
}
else
{
root->rchild=insert(root->rchild,x);
}
return root;
}
    void inorder(struct node *root)
    {
        if(root!=NULL)
        {
            inorder(root->lchild);
            printf("%d\n",root->data);
            inorder(root->rchild);
        }
    }
    void preorder(struct node *root)
    {
        if(root!=NULL)
        {
            printf("%d\n",root->data);
            preorder(root->lchild);
            preorder(root->rchild);
        }
    }
    void postorder(struct node *root)
    {
         if(root!=NULL)
    {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d\n",root->data);
    }
}
    int main()
    {  
        struct node *root=NULL;
        int choice,v;
        char ch;
        while(1)
        {
            printf("1)create 2)inorder 3)preorder 4)postorder 5)exit\n");
            scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("enter the data =");
                   scanf("%d",&v);
                   root=insert(root,v);
                   break;
            case 2:printf("inorder traversal\n");
                   inorder(root);
                   break;
            case 3:printf("preorder traversal\n");
                   preorder(root);
                   break;
            case 4:printf("postorder traversal\n");
                   postorder(root);
                   break;
            case 5:exit(0);
        }
        }
        return 0;
}