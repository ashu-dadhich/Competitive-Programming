#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	while(t>0)
	{
	    char s[1001]; long long int count=2;
		scanf("%s",s);
       	for(int i=1;i<strlen(s);i++)
		{
			if(s[i]>=s[i-1])
			{
				count+=(int)(s[i]-s[i-1])+1;
			}
			else
			{
				count+=26+(s[i]-s[i-1])+1;
			}
		}
		if(11*strlen(s)>=count) printf("YES\n");
		else printf("NO\n");
		t--;
	}
	return 0;
}
