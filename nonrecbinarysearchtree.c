#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int data;
	struct node *right_child;
	struct node *left_child;
};

struct stack {
    int top;
    struct node* items[100];
};

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

void nrec_in(struct node* root) {
    struct stack* stack = (struct stack*)malloc(sizeof(struct stack));
    stack->top = -1;
    struct node* current = root;
    while (current != NULL || stack->top != -1) {
        while (current != NULL) {
            stack->items[++stack->top] = current;
            current = current->left_child;
        }
        current = stack->items[stack->top--];
        printf("%d ", current->data);
        current = current->right_child;
    }
}

void nrec_pre(struct node* root) {
    struct stack* stack = (struct stack*)malloc(sizeof(struct stack));
    stack->top = -1;
    struct node* current = root;
    while (current != NULL || stack->top != -1) {
        while (current != NULL) {
            printf("%d ", current->data);
            stack->items[++stack->top] = current;
            current = current->left_child;
        }
        current = stack->items[stack->top--];
        current = current->right_child;
    }
}

void nrec_post(struct node* root) {
    struct stack* stack1 = (struct stack*)malloc(sizeof(struct stack));
    struct stack* stack2 = (struct stack*)malloc(sizeof(struct stack));
    stack1->top = -1;
    stack2->top = -1;
    struct node* current = root;
    stack1->items[++stack1->top] = current;
    while (stack1->top != -1) {
        current = stack1->items[stack1->top--];
        stack2->items[++stack2->top] = current;
        if (current->left_child != NULL) {
            stack1->items[++stack1->top] = current->left_child;
        }
        if (current->right_child != NULL) {
            stack1->items[++stack1->top] = current->right_child;
        }
    }
    while (stack2->top != -1) {
        current = stack2->items[stack2->top--];
        printf("%d ", current->data);
    }
}
int main() 
{
	struct node *root;
	int choice;
	int v,n,i;
while(1)
{
		printf("\n 1.create 2.insert  3.inorder 4.preorder 5.postorder 8.exit");
		printf("\n\n enter your choice=");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("\n enter root value= ");
				   scanf("%d",&v);
				   root=create(v);
				   break;
			case 2:printf("No of value to be inserted: ");
			scanf("%d",&n);
			printf("enter values=");
			for(i=1;i<=n;i++)
			{
				scanf("%d",&v);
				insert(root,v);
			}
			break;
		    case 3: printf("\n inorder traversal\n");
 					nrec_in(root);
 			break;
 			case 4:printf("\n preorder traversal\n");
 			       nrec_pre(root);
 			       break;
            case 5:printf("\n preorder traversal\n");
 			       nrec_post(root);
 			       break;
				     
	        case 6: exit(0); 
      }
    }
    return 0;
}