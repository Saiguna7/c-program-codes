#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node{
	int data;
	struct node *rchild;
	struct node *lchild;
};

struct node* create();
void inorder(struct node *t);
void preorder(struct node *t);
void postorder(struct node *t);
struct node* create()
{
	int value;
	char ch='y';
	struct node *t;
	t=(struct node *)malloc(sizeof(struct node));
	t->lchild=t->rchild=NULL;
	printf("Enter the DATA : ");
	scanf("%d%c",&value,&ch);
	t->data=value;
	printf("Do you want to create left child of %d ",t->data);
	printf("Enter your option y/n");
	scanf("%c",&ch);
	if(ch=='y')
	{
		t->lchild=create();
	}
	printf("Do you want to create right child of %d ",t->data);
	scanf("%c%c",&ch,&ch);
	
	if(ch=='y')
	{
		t->rchild=create();
	}
	return t;
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
	if(t)
	{
		printf("%d\n",t->data);
		preorder(t->lchild);
		preorder(t->rchild);
	}
}

void postorder(struct node *t)
{
	if(t)
	{
		postorder(t->lchild);
		postorder(t->rchild);
		printf("%d\n",t->data);
	}
}

int main()
{
	struct node *root;
	int choice;
	while(1)
	{
		printf("1. Create\t2.Inorder\t3.Preorder\t4.Postorder\t5.Exit");
		printf("\nEnter the Choice : ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1: root=create();
			break;
			
			case 2: printf("Inorder Traversal\n");
			inorder(root);
			break;
			
			case 3: printf("Preorder Traversal\n");
			preorder(root);
			break;
			
			case 4: printf("Postorder Traversal\n");
			postorder(root);
			break;
			
			case 5: exit(0);
		}
	}
	return 0;
}
