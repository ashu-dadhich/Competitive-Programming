#include<iostream>
#include<stdio.h>
#include<string.h>
#define mod 10000009
using namespace std;
int main()
{
	char a[60][61],b[61]; 
    int k,n; scanf("%d%d",&k,&n);
	for(int i=0;i<k;i++) scanf("%s",a[i]);
	for(int i=0;i<n;i++)
	{
		int found=0;		
		scanf("%s",b);	
		if(strlen(b)>=47) 
		{
			printf("Good\n"); continue;
		}		
		for(int j=0;j<k;j++)
		{
			for(int l=0;l<=strlen(b)-strlen(a[j]);l++)
			{
				int index=0;				
				for(int m=0;m<strlen(a[j]);m++)
				{
					if(a[j][m]==b[l+index])
					{
						found=1;
					}
					else 
					{
						found=0; break;	
					}
					index++;
				}
				if(found==1) break;
			}
			if(found==1) break;
		}
		if(found==1) printf("Good\n");
		else printf("Bad\n");
			
	}	
    	
      
	return 0;
}
