#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
	int t; cin>>t;
	while(t>0)
	{
		int n; cin>>n;
		int c4=0,count=0;
		while(true)
		{
			
			if(n==4)
			{
				c4=0; break;
			}			
			if(n%7==0) 
			{
				c4=n; break;
			}
			else
			{
				n=n-4; 
				count++;
			}
			if(count==8 || n<7) 
			{
				c4=-1;				
				break;	
			}
		}
		printf("%d\n",c4);
		t--;
	}
	return 0;
}
