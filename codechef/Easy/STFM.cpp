#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
	int n; long long int m;
	scanf("%d%lld",&n,&m);
    long long int pi=0,sum=0,fx=0,*fact;
    fact=new long long int[10000003];
    fact[1]=1;
    for(long long int i=2;i<10000003;i++)
    {
        fact[i]=i*fact[i-1];
        if(fact[i]%m!=0) fact[i]%=m;
        
    }	
    while(n>0)
	{
        scanf("%lld",&pi);        
        if(pi>m) pi=pi%m;
        if(pi==0) pi=m;
        fx=pi;
        fx=(pi*pi); if(fx>m) fx%=m;
        if(fx==0) fx=m;  
        fx*=(pi+1); fx/=2; fx%=m;
        fx+=(fact[pi+1])-1;
        fx%=m;
        //cout<<pi<<" "<<fx<<endl;
        sum+=fx; 
        sum%=m;
		n--;
	}
    printf("%lld\n",sum);
	
	return 0;
}
