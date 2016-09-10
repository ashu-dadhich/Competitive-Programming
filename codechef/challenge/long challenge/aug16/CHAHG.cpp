#include <iostream>
#include <cstdio>
#include <string.h>
#include <cmath>
#define sub 1000000000
using namespace std;
long long int big=100000000000007;

int main()
{
	int t; scanf("%d",&t);
	long long int rangex[2],rangey[2],index=0;
	while(t-->0)
	{
		int n;
		long long int h[13]={0},m[13]={0},curtime=0;
		scanf("%d",&n);
		int alt[13]={0};
		for(int i=0;i<n;i++)
		{
			scanf("%lld%lld",&h[i],&m[i]);
			if(i==0) continue;
			if(h[i]>h[i-1]) alt[i]=1;
			else if(h[i]<h[i-1]) alt[i]=0;
			else alt[i]=2;
		}
		if(n==1)
		{
			printf("1\n0 Inf\n");
			continue;
		}
		int state=1,count=0; //zigzag
		index=0;
		while(true)
		{
			//cerr<<"curtime= "<<curtime<<endl;
			//cout<<"alt\n";
			//for(int i=1;i<n;i++) cerr<<alt[i]<<" ";
			//cout<<endl;
			state=1;
			if(n==2)
			{
				if(h[1]==h[0]) state=0;
				else state=1; 
			}
			for(int i=2;i<n;i++)
			{	
				if(alt[i-1]==0)
				{
					if(alt[i]==2 || alt[i]==0)
					{
						state=0; break;
					}
				}
				else if(alt[i-1]==1)
				{
					if(alt[i]==2 || alt[i]==1) { state=0; break; } 
				}
				else
				{
					state=0; break;
				}
			}			
			//cout<<"state= "<<state<<endl;		
			if(state==1)
			{
				count++;
				rangex[index]=curtime;
			}
			// find time when variation will occur
			long long int mintime=big,tt=big;
			for(int i=1;i<n;i++)
			{
			//	cout<<"i= "<<i<<endl;
				if(alt[i]==1)
				{
					if(m[i-1]>m[i])
					{
						tt=ceil( ((float)(h[i]-h[i-1]))/((float)(m[i-1]-m[i])) );
						if(tt<mintime) mintime=tt;
					}
				}
				else if(alt[i]==0)
				{
					if(m[i]>m[i-1])
					{
						tt=ceil( ((float)(h[i-1]-h[i]))/((float)(m[i]-m[i-1])) );
						if(tt<mintime) mintime=tt;
					}
				}
				else 
				{
					if(m[i]!=m[i-1]) 
					{
						tt=1;
						if(tt<mintime) mintime=tt;
					}
				}
			//	cout<<"tt= "<<tt<<endl;
			}
			//cout<<"mintime= "<<mintime<<endl;
			if(mintime==big)
			{
				//state will never change now
				if(state==1)	rangey[index++]=big; //goes to inf
				break;
			}
			else
			{
				if(state==1) 
				{
					rangey[index++]=curtime+mintime-1;
					
				}
				curtime+=mintime;
				long long int limit=big,ff=0,mx=0;
				for(int i=0;i<n;i++)
				{
					h[i]+=m[i]*mintime;
					if(h[i]>sub) 
					{
						ff=1;
						if(h[i]-sub>mx) mx=h[i]-sub;
					}
				}
				if(ff==1) 
				{
					for(int i=0;i<n;i++)
					{
						h[i]-=mx;
					}
				}
				for(int i=0;i<n;i++)
				{
					if(i==0) continue;
					if(h[i]>h[i-1]) alt[i]=1;
					else if(h[i]<h[i-1]) alt[i]=0;
					else alt[i]=2;
				}
				//break;
			}
		}
		if(count>1)
		{
			if(rangey[0]==rangex[1]-1)
			{
				rangey[0]=rangey[1];				
				count--;
			}
		}
		printf("%d\n",count);
		for(int i=0;i<count;i++)
		{
			if(rangey[i]==big) printf("%lld Inf\n",rangex[i]);
			else printf("%lld %lld\n",rangex[i],rangey[i]);
		}
	}
	return 0;
}