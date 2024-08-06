#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *rchild;
struct node *lchild;
};
struct node *create(int x);
void inorder(struct node *);
void preorder(struct node *);
void postorder(struct node *);
struct node *create(int x)
{
struct node *t;
t=(struct node*)malloc(sizeof(struct node));
t->data=x;
t->lchild=NULL;
t->rchild=NULL;
return t;
}
struct node *insert(struct node * r,int x)
{
if (r==NULL)
return create(x);
else if(x>r->data)
r->rchild=insert(r->rchild,x);
else
r->lchild=insert(r->lchild,x);
return r;
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
     printf("1.create  2.insert   3. inorder  4.preorder  5.postorder\n  6.exit");
     printf("\n enter your choice");
     scanf("%d",&choice);
     switch(choice)
     {
        case 1:printf("Enter root value");
 scanf("%d",&v);
 root=create(v);
        break;
        case 2:  printf("No. of values to be inserted:");
   scanf("%d",&n);
   printf("Enter values");
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