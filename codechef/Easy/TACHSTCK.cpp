#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int n; 
	long long int a[100001]={0},d,count=0;	
	scanf("%d%lld",&n,&d);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a,a+n);
	for(int i=0;i<n-1;i++)
	{
		if(a[i+1]-a[i]<=d) 
		{
			count++; i++;
		}
	}
	printf("%lld\n",count);
	return 0;
}
