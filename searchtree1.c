#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
int data;
struct node *lchild;
struct node *rchild;
};

struct node *create()
{   int value;
    struct node *t;
    printf("enter data=\n");
    t=(struct node *)malloc(sizeof(struct node));
    t->lchild=t->rchild=NULL;
    printf("enter data");
    scanf("%d",&value);
    t->data=value;
struct node *insert(struct node *root,int x)
{
char ch='y';
if(root==NULL)
{
return create(x);
}
printf("do you want to create left child of%d\n y/n? ",root->data);
scanf("%c %c",&ch,&ch)
if(ch=='y' && root->data<=x)
{
root->lchild=insert(root->lchild,x);
}
printf("do you want to create right child of%d\n y/n? ",root->data);
scanf("%c %c",&ch,&ch)
else
{
root->rchild=insert(root->rchild,x);
}
return root;
}
    void inorder(struct node *t)
    {
        if(t!=NULL)
        {
            inorder(t->lchild);
            printf("%d\n",t->data);
            inorder(t->rchild);
        }
    }
    void preorder(struct node *t)
    {
        if(t!=NULL)
        {
            printf("%d\n",t->data);
            preorder(t->lchild);
            preorder(t->rchild);
        }
    }
    void postorder(struct node *t)
    {
         if(t!=NULL)
    {
        postorder(t->lchild);
        postorder(t->rchild);
        printf("%d\n",t->data);
    }
}
    int main()
    {  
        struct node *root=NULL,x;
        int choice;
        while(1)
        {
            printf("1)create 2)inorder 3)preorder 4)postorder 5)exit\n");
            scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                 root=create();
                 if(root!=NULL)
                 root=insert(root,x);
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