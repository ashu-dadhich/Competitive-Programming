#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	while(t>0)
	{
	    int n; char s[100001]; long long int count=0;
		scanf("%d%s",&n,s);
		for(int i=0;i<n;i++)
		{
			if(s[i]=='1') count++;
		}
		count=(count*(count+1))/2;
		printf("%lld\n",count);
		t--;
	}
	return 0;
}
