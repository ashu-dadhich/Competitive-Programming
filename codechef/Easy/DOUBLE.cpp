#include<iostream>
#include<stdio.h>
using namespace std;
	int main()
    {
        int t;scanf("%d",&t);
        while(t>0)
        {
            int length;
			scanf("%d",&length);
            if(length%2==0) printf("%d\n",length);
            else printf("%d\n",length-1);
            t--;
	 	}
        return 0;
    }


