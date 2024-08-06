struct stack
{
    int top;
    struct node *item[100];
};
void nrec_in(struct node *root)
{
    struct stack* stack=(struct stack*)malloc(sizeof(struct stack));
    stack->top=-1;
    struct node *c=root;
    while(c!=NULL||stack->top!=-1){
        while(c!=NULL)
        {
            stack->item[++stack->top]=c;
            c=c->lchild;
        }
        c=stack->item[stack->top--];
        printf("%d",c->data)
        c=c->rchild;
    }
}