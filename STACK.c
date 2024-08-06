#include<stdio.h>
#include<stdlib.h>
#define MAX 50
struct node 
{
	int data;
	struct node *right_child;
	struct node *left_child;
};
int top=-1;
struct node *stack[MAX];
struct node *create(int x)
 {
	struct node *temp;
	temp =(struct node*)malloc(sizeof(struct node));
	temp -> data = x;
	temp ->left_child = NULL;
	temp ->right_child = NULL;
	return temp;
}
struct node* insert(struct node * root, int x)
{
	if(root == NULL)
	return create(x);
	else if (x > root -> data)
	root -> right_child = insert(root -> right_child, x);
	else
	root -> left_child = insert(root -> left_child, x);
	return root;
}
void nrec_in(struct node *root)
{
	struct node *ptr=root;
	if(ptr==NULL)
	{
		printf("tree is empty\n");
		return;
	}
	while(1)
	{
		while(ptr->left_child!=NULL)
		{
			push_stack(ptr);
			ptr=ptr->left_child;
		}
		while(ptr->right_child==NULL)
		{
			printf("%d ",ptr->data);
			if(stack_empty())
			return;
			ptr=pop_stack();
			
		}
		printf("%d ",ptr->data);
		ptr=ptr->right_child;
	}
	printf("\n");
}//end of nre_in()
void push_stack(struct node *item)
{
	if(top==(MAX-1))
	{
		printf("STACK overflow\n");
		return;
	}
	else
	{
		stack[++top]=item;
	}
}
int stack_empty()
{
	if(top==-1)
	return 1;
	else
	return 0;
}
struct node* pop_stack( )
{
	if(top==-1)
	{
		printf("stac underflow\n");
	}
	else 
	{
		 return stack[top--];
		
	}
}
void nrec_pre(struct node *root)
{
	struct node *ptr = root;
	if(ptr==NULL)
	{
		printf("Tree is empty\n");
		return;
	}
	push_stack(ptr);
	while(!stack_empty())
	{
		ptr=pop_stack();
		printf("%d ",ptr->data);
		if(ptr->right_child!=NULL)
		push_stack(ptr->right_child);
		if(ptr->left_child!=NULL)
		push_stack(ptr->left_child);
	}
	printf("\n");
}
int main()
 {
 	 struct node *root,*temp;
 	int choice;
 	int v,n,i,k;
 	
 
 	while(1)
 	{
 		printf(" 1.create  2.insert 3.inorder 4.preorder  5.exit/n ");
 		printf("\n enter the your choice ");
 		scanf("%d",&choice);
 		switch(choice)
 		{
 			case 1: printf("Enter root value");
 			        scanf("%d",&v);
 			        root=create(v);
 			        break;
 			case 2: printf("Enter values");
 			        scanf("%d",&n);
 			        for(i=1;i<=n;i++)
 			        {  
 			             scanf("%d",&v);
 			             insert(root,v);
					 }
                    break;
 			case 3: printf("\n inorder traversal");
 					nrec_in(root);
 			break;
 			case 4:printf("\n preorder traversal");
 			       nrec_pre(root);
 			       break;
 			/*case 5:printf("\n postorder traversal\n");
			       postorder(root);
				   break; */
				     
	        case 5: exit(0); 
			          
		 }
	 }
	 return 0;
 }