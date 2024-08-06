#include<stdio.h>
#include<stdlib.h>
int de[20][20],vis[20];
int d[10];
int f=-1,r=-1;
int n,i,j;
void enque(int x)
{
	if(f==-1)
	{
		f=r=0;
	}
	else
	r++;
    d[r]=x;
}
int deque()
{
	int p;
	if(f==-1)
	return -1;
	else if(f==r)
	{
		p=d[f];
		f=r=-1;
	}
	else
	{
		p=d[f];
		f++;
	}
	return p;
}
void bfs(int v)
{
	if(!vis[v])
	{
		enque(v);
		vis[v]=1;
	}
	for(i=1;i<=n;i++)
	{
		if(!vis[i]&&de[v][i])
		{
			enque(i);
			vis[i]=1;
		}
	}
	int p=deque();
	if(p!=-1)
	{
		printf("\n  traversing ..........%d",p);
		bfs(p);
	}
}
int main()
{
	printf("\n enter no of vertices  ");
	scanf("%d",&n);
	printf("\n enter elements ");                                  
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d ",&de[i][j]);
		}
	}
	int v;
	printf("\n enter vertex to start ");
	scanf("%d",&v);
	bfs(v);
	printf(" unreachable vertices are\n");
	int flag=0;
	for(i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			flag++;
			printf("not reachable ......%d\n",i);
		}
	}
	if(flag==0)
	printf("no unreachable vertices\n");
}

