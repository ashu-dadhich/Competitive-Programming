#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
	int t; cin>>t;
	while(t>0)
	{
		int n;
		cin>>n;
		int a[101],c1=0,c2=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			for(int j=0;j<i;j++)
			{
				if(a[j]>a[i]) c1++;
			}
			if(i==0) continue;
			if(a[i-1]>a[i]) c2++;
		}
		if(c1==c2) printf("YES\n");
		else printf("NO\n");
		t--;
	}
	return 0;
}
