#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	while(t>0)
	{
		int n,c,q,l,r;
		scanf("%d%d%d",&n,&c,&q);
		for(int i=1;i<=q;i++)
		{
			scanf("%d%d",&l,&r);
			if(c>=l && c<=r)
			{
				int dif=c-l;
				c=r-dif;
			}
		}	
		printf("%d\n",c);
       	t--;
	}
	return 0;
}
