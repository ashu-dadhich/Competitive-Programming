#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<string.h>
using namespace std;
int main()
{
   	int t;  scanf("%d",&t);
    while(t>0)
    {
        int n,a,b,tempa,tempb,count1a=0,count0a=0,count1b=0,count0b=0;
		scanf("%d%d%d",&n,&a,&b);
		tempa=a; tempb=b;
		while(tempa>0)
		{
			if(tempa%2==1) count1a++;
			tempa/=2;
		}
		count0a=n-count1a;
		while(tempb>0)
		{
			if(tempb%2==1) count1b++;
			tempb/=2;
		}
		count0b=n-count1b;
		int count=min(count1a,count0b)+min(count0a,count1b);
		long long int ans=0;		
		for(int i=1;i<=count;i++)
		{
			ans+=pow(2,n-i);
		}
		printf("%lld\n",ans);
        t--;
    }
	return 0;
}
