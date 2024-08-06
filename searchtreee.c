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

    struct node *t,*r;
    t=(struct node *)malloc(sizeof(struct node));
    t->lchild=t->rchild=NULL;
    if(t->data!=NULL)
    {
    char ch;
    printf("do u want to create more data");
    scanf("%c",&ch);
    if(ch=='y' && ch)
    {

    }
    }
        t->data=x;
        return t;
  
}
struct node *insert(struct node *root,int x)
{
char ch;
if(root==NULL )
{
    root=create(x);
}
if(x<=root->data)
{
printf("%d<=%d if u want left child create y/n?",root->data,x);
scanf("%c %c",&ch,&ch);
if(ch=='y' && ch=='y')
{
root->lchild=insert(root->lchild,x);
}
if(x>root->data)
{
printf("%d>%d if u want right child create y/n?",root->data,x);
scanf("%c %c",&ch,&ch);
if(ch=='y' && ch=='Y')
{
root->rchild=insert(root->rchild,x);
}
}
return root;
}
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
    struct node *create1()
    {                   struct node *root=NULL;
                     int x; 
                     printf("enter the data=");
                     scanf("%d",&x);
                     root=insert(root,x);
    }    
                    struct node *inorder1()
    {
                     printf("inorder traversal\n");
                     inorder(root);
    }    
                    struct node *create3(struct node *r)
    {
                     printf("enter the data=");
                     scanf("%d",&x);
                     root=insert(root,x);
                     break;
    }    
    struct node *create4(struct node *r)
    {
                     r=insert(r);
    }    
    struct node *exit()
    {
                    exit(0);
    }    
                    
                    
int main()
    {  
        struct node *root;
        int choice,x;
        while(1)
        {
            printf("1)create 2)inorder 3)preorder 4)postorder 5)exit\n");
            scanf("%d",&choice);
        switch(choice)
        {
            case 1:  
                     root=create1();

                     break;
            case 2:
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