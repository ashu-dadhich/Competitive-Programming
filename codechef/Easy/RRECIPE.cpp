#include<iostream>
#include<stdio.h>
#include<string.h>
#define mod 10000009
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	while(t>0)
	{
		char s[1000001]; 
        long long int count=1;	
        scanf("%s",s);	
        int length=strlen(s),flag=1;
        for(int i=0;i<length;i++)
        {
            if(i<=length-i-1)
            {
                if(s[i]!=s[length-i-1])
                {
                    if(s[i]=='?' || s[length-i-1]=='?') continue;
                    else{ flag=0; break; } 
                }
                else
                {
                    if(s[i]=='?') count*=26;
                }
            }
            else break;
            if(count>mod) count%=mod;
        }
        if(flag==0) count=0;
         printf("%lld\n",count);
		t--;
	}
	return 0;
}
