#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<string.h>
#define mod 1000000007
using namespace std;
long long int a[100001]={0},answer=0;
long long int n,x,m;
//unction for extended Euclidean Algorithm
int gcdExtended(int a, int b, int *x, int *y);

// Function to find modulo inverse of a
int modInverse(int a, int m)
{
    int x, y;
    int g = gcdExtended(a, m, &x, &y);
    //if (g != 1)
      //  cout << "Inverse doesn't exist";
    //else
            // m is added to handle negative x
        int res = (x%m + m) % m;
    //    cout << "Modular multiplicative inverse is " << res;
    
	return res;
}

// C function for extended Euclidean Algorithm
int gcdExtended(int a, int b,  int *x,  int *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }

    int x1, y1; // To store results of recursive call
    int gcd = gcdExtended(b%a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;

    return gcd;
}


int main()
{
	int t; scanf("%d",&t);    	
    while(t>0)
	{
        long long int cof=1;		
        scanf("%lld%lld%lld",&n,&x,&m);
		if(m>=mod) m%=mod;	
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			if(a[i]>=mod) a[i]%=mod;
		}
        if(x<3)
		{
			if(x==2)
			{
				long long int p=a[1];			
				p=m*p;	if(p>=mod) p%=mod;
				p+=a[2]; if(p>=mod) p%=mod;
				answer=p;
			} 
			if(x==1) answer=a[1];
		}
		else
		{
			if(m==1)
			{			
				for(int j=1;j<=x;j++)
				{
					a[j]=a[j]+a[j-1];
				}	
				answer=a[x]; if(answer>=mod) answer%=mod;
			}	
			else 
			{
				answer=0;
				long long int p=1,start=1,end=m;	
				for(int i=x;i>0;i--)
				{						
                    p=a[i]; if(p>=mod) p%=mod;
                    p*=cof;	if(p>=mod) p%=mod;                    
                    cof*=end; if(cof>=mod) cof%=mod; 
					cof*=modInverse(start,mod); 
					if(cof>=mod) cof%=mod;	                    
                    //cout<<"p="<<p<<endl;	
                    start++; end++;     
                    //cout<<"cof= "<<cof<<endl;                    
                    answer+=p; if(answer>=mod) answer%=mod;
				}
			}
		}	
		printf("%lld\n",answer);
		t--;
	}
	return 0;
}
