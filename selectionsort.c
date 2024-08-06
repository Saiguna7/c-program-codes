#include<stdio.h>
int main()
{
    int arr[]={23,13,25,2,4,21,3,6,0,13};
    int n=10;
    int i,j,position,swap;
    for(i=0;i<n-1;i++)
    {
        position=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[position]>arr[j])
            position=j;
        }
        if(position!=1)
        {
            swap=arr[i];
            arr[i]=arr[position];
            arr[position]=swap;
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
            }
            return 0;
}