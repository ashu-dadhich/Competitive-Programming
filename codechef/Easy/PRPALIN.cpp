#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
	int main()
    {
        
            int N;scanf("%d",&N);
            for(int i=N;i<1000000000;i++)
            {
                int prime=1;
                if(N>5 && (i%10==1 || i%10==3 || i%10==7 || i%10==9))
                {
                    int tempi=i;
                    
                    int num=0;
                    while(tempi>0)
                    {
                        num=num*10+(tempi%10);
                        tempi/=10;
                    }
                    
                    if(i!=num) continue; 
                   
                    for(int j=2;j<=sqrt(i);j++)
                    {
                        if(i%j==0)
                        {
                            prime=0;
                            break;
                        }
                    }
                    if(prime==1) 
                    {
                        printf("%d\n",i);
                        break;
                    }
                }
                
                
                if(N<=5)
                {
                    for(int j=N;j<=5;j++)
                    {
                        if(j==2 || j==3 || j==5)
                        {
                            printf("%d\n",j);
                            prime=1;
                            break;
                        }
                        
                    }
                    if(prime==1) break;
                }
            }

       return 0;
    }


