#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *rchild;
struct node *lchild;
};
struct node *create(int x)
{
struct node *t;
t=(struct node *)malloc(sizeof(struct node));
t->data=x;
t->lchild=NULL;
t->rchild=NULL;
return t;
}
struct node *insert(struct node *root,int x)
{
char ch;
if(root==NULL )
{
    root=create(x);
}
if(x<root->data)
{
printf("%d<%d if u want left child then create y/n? ",x,root->data);
scanf("%c %c",&ch,&ch);
if(ch=='y' || ch=='y')
{
root->lchild=insert(root->lchild,x);
}
}
else if(x>root->data)
{
printf("%d>%d if u want right child the  create y/n? ",x,root->data);
scanf("%c %c",&ch,&ch);
if(ch=='y' || ch=='Y')
{
root->rchild=insert(root->rchild,x);
}
}
return root;
}

void inorder(struct node *t)
   {  
       if(t!=NULL)
       {  
         inorder(t->lchild);
         printf("%d ",t->data);
         inorder(t->rchild);
  }
   }
void preorder(struct node *t)
{
   if(t)
   {  
     printf("%d ",t->data);
     preorder(t->lchild);
     preorder(t->rchild);
   }
}
void postorder( struct node *t)
{
   if(t)
   {  
   
     postorder(t->lchild);
     postorder(t->rchild);
     printf("%d ",t->data);
       
   }
}
   int main()
   {
   struct node *root;
   int choice;
   int v,n,i;
   while(1)
   {
     printf("\n1.create  2.insert   3. inorder  4.preorder  5.postorder  6.exit");
     printf("\n\nenter your choice=");
     scanf("%d",&choice);
     switch(choice)
     {
        case 1:printf("\nEnter root value=");
 scanf("%d",&v);
 root=create(v);
        break;
        case 2:  
        printf("No. of values to be inserted:");
   scanf("%d",&n);
   printf("Enter values=");
   for(i=1;i<=n;i++)
   {
   
    scanf("%d",&v);
   insert(root, v);
}
break;
        case 3: printf("inorder traversal\n");
                inorder(root);
                 break;
        case 4: printf("\n preorder traversal\n");
                 preorder(root);
                  break;
        case 5:  printf("\n postorder traversal\n");
                 postorder(root);
                 break;
        case 6: exit(0);
}

   }
   return 0;
}