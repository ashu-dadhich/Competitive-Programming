#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
    long long int a[51]={0};
	while(t>0)
	{
	    long long int n,k,count=0;
		scanf("%lld%lld",&n,&k);
       	for(int i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			if(a[i]%2==0) count++;
		}
		if(k==0)
		{
			if(count<n) printf("YES\n");
			else printf("NO\n");
		}
		else if(count>=k) printf("YES\n");
		else printf("NO\n");
		t--;
	}
	return 0;
}
