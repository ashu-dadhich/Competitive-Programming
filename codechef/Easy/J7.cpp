#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
	float p,s,l,b;
	int t; cin>>t;
	while(t>0)
	{
		cin>>p>>s;
		l=(p-sqrt((p*p)-24*s))/12;
		b=(p-(8*l))/4;
		cout<<(l*l*b)<<endl;
		t--;
	}
	return 0;
}
