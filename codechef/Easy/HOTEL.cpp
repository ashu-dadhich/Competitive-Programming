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
		int a[101]={0},d[101]={0};
		for(int i=0;i<n;i++) cin>>a[i];
		for(int i=0;i<n;i++) cin>>d[i];
		/*for(int i=0;i<n-1;i++)
		{
			for(int j=0;j<n-1;j++)
			{
				if(i==j) continue;
				if(a[j]>a[j+1])
				{
					int temp=a[j];
					a[j]=a[j+1]; a[j+1]=temp;
					temp=d[j]; d[j]=d[j+1]; d[j+1]=temp;
				}
			}
		}*/ //using sort answer is 0.01 time faster
		int min=10000,max=0,tempmax=0,count=0;
		while(count!=n)
		{
			for(int i=0;i<n;i++)
			{
				if(d[i]<min) min=d[i];
			}
			tempmax=0;			
			for(int i=0;i<n;i++)
			{
				if(a[i]<min && d[i]>=min)
				{
					tempmax++;
				}
			}			
			if(tempmax>max) max=tempmax;
			for(int i=0;i<n;i++)
			{
				if(d[i]==min)
				{
					d[i]=100000; a[i]=100000;
					count++;
				}
			}
			min=10000;		
		}		
		printf("%d\n",max);
		t--;
	}
	return 0;
}
