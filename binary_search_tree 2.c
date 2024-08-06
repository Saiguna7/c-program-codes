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
t=(struct node*)malloc(sizeof(struct node));
t->data=x;
t->lchild=t->rchild=NULL;
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
struct node* search(struct node* root,int x)
{
	if(root == NULL || root -> data == x)
	return root;
	else if (x > root -> data)
	return search(root -> rchild, x);
	else  
	return search(root -> lchild, x);
}
struct node* find_minimum(struct node* root)
{
	if(root == NULL)
	return NULL;
	else if (root -> lchild !=NULL)
	return find_minimum(root ->lchild);
	return root;
}
struct node* find_maximum(struct node* root)
{
	if(root == NULL)
	return NULL;
	else if (root -> rchild !=NULL)
	return find_maximum(root->rchild);
	return root;
}
int main()
{
	struct node *root,*temp;
	int choice;
	int v,n,i;
	while(1)
	{
    	printf("1.create  2.insert   3. inorder  4.preorder  5.postorder  6.search 7.find_minimum 8.find_maximum\n 9.exit");
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
        	case 6: printf("\n enter the element\n ");
        	        scanf("%d",&v);
        	        root=search(root,v);
        	        if(root==NULL)
        	        printf("Element not found");
        	        else 
        	        printf("\nElement  found ");
					break;
			case 7: temp=find_minimum(root);
			        printf("%d\n",temp->data);
			        break;
		    case 8: temp=find_maximum(root);
			        printf("%d\n",temp->data);
			        break;
			case 9:exit(0);        
		}

   }
   return 0;
}
