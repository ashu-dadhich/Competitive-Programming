#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
	int n,t,*s;
	scanf("%d",&t);
	while(t>0)
	{	
		scanf("%d",&n);		
		s=new int[n];
		for(int i=0;i<n;i++) scanf("%d",&s[i]);
		sort(s,s+n);		
		int min=s[1]-s[0],diff;		
		for(int i=1;i<n-1;i++)
		{
			diff=s[i+1]-s[i];
			if(diff<min)
			{
				min=diff;
			}
			if(min==0) break;
		}
		printf("%d\n",min);
		delete[] s;	
		t--;	
	}	
	return 0;
}	
