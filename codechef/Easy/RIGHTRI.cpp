#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
	int n; scanf("%d",&n);
    int count=0;
	while(n>0)
	{
	int x1,y1,x2,y2,x3,y3; 
        scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
        int d12=pow(x2-x1,2)+pow(y2-y1,2);
	int d23=pow(x3-x2,2)+pow(y3-y2,2);
	int d13=pow(x3-x1,2)+pow(y3-y1,2);
        if( (d12+d23)==d13 || (d12+d13)==d23 || (d13+d23)==d12) count++;
   		n--;
	}
    	printf("%d",count);
	return 0;
}
