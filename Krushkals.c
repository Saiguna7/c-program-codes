#include<stdio.h> 
#include<conio.h>
#include<stdlib.h>
int i,j,k,a,b,u,v,n,ne=1;
int min, mincost=0, adj[25][25], parent[25];
int find(int i)
{
while(parent[i]) 
i=-parent[i]; 
return i;
}
int uni(int i,int j)
{
if(i!=j) 
{
parent[j]=i; 
return 1;
}
return 0;
}
void main()
{
    printf("\nEnter thee no. of vertices:");
    scanf("%d",&n);
    printf("\nEnter the cost cost adjacency matrix:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&adj[i][j]);
            if(adj[i][j]==0)
               adj[i][j]=999;
        }
    }
printf("the edges of Minimum Cost Spanning Tree are\n");
while(ne<n)
{
    for(i=1,min=999;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(adj[i][j]<min)
            {
                min=adj[i][j];
                a=u=i;
                b=v=j;
            }
        }
    }
    u=find(u);
    v=find(v);
    if(uni(u,v))
    {
        printf("%d edge (%d,%d) =%d\n",ne++,a,b,min);
        mincost +=min;
    }
    adj[a][b]=adj[b][a]=999;
}
printf("\n\tMinimum cost = %d\n",mincost);
}