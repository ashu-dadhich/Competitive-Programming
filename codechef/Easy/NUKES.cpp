#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int a,n,k;
	scanf("%d%d%d",&a,&n,&k);
	int current=0,next=0;
	for(int i=0;i<k;i++)
	{
		current=a%(n+1);
		next=a/(n+1);
		printf("%d ",current);
		current=next;
		a=a/(n+1);
	}
	printf("\n");
	return 0;
}
