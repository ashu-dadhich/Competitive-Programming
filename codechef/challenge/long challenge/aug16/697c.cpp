#include <iostream>
#include <stdio.h>
using namespace std;
int val[100001]={0},pred[100001]={0},root;
int pathu[100000],pathv[100000],indexu=0,indexv=0;
int index=0,path[100000],path2[100000],index2=0;
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&val[i]);
	} 
	for(int i=1;i<n;i++)
	{
		int u,v; scanf("%d%d",&u,&v);
		pred[v]=u;
	}
	for(int i=1;i<=n;i++) 
		if(pred[i]==0) { root=i; break; }

	for(int query=1;query<=q;query++)
	{
		int type,ul,ur,vl,vr,common=root,indexu=0,indexv=0;
		index2=0;index=0;
		scanf("%d%d%d",&type,&ul,&ur);
		int temp=ul;
		while(temp!=0)
		{
			pathu[indexu++]=temp;
			temp=pred[temp];
		}
		//cout<<"pathu=\n";
		//for(int i=0;i<indexu;i++) cout<<pathu[i]<<" ";
		//cout<<endl;

		temp=ur;
		while(temp!=0)
		{
			pathv[indexv++]=temp;
			temp=pred[temp];
		}
		//cout<<"pathv=\n";
		//for(int i=0;i<indexv;i++) cout<<pathv[i]<<" ";
		//cout<<endl;

		int tempindexu=indexu-1,tempindexv=indexv-1;
		while(true)
		{
			if(tempindexu>=0 && tempindexv>=0)
			{
				if(pathu[tempindexu]==pathv[tempindexv])
				{
					common=pathu[tempindexu];
				}
				else 
				{
					tempindexu++;
					break;
				}
				tempindexu--; tempindexv--;
			}
			else 
			{
				tempindexu++;
				break;
			}
		}
		//cout<<"common= "<<common<<endl;
		index=0;
		/*if(tempindexu<0 || tempindexv<0)
		{
			if(tempindexu<0)
			{
				for(int i=tempindexv;i>=0;i--) 
					path[index++]=pathv[i];
			}
			else if(tempindexv<0)
			{
				for(int i=0;i<=tempindexu;i++)
					path[index++]=pathu[i];
			}
			else path[index++]=common;
		}*/
		//else
		{
			for(int i=0;i<=tempindexu;i++)
			{
				path[index++]=pathu[i];
			}
			for(int i=tempindexv;i>=0;i--)
			{
				path[index++]=pathv[i];
			}
		}
		index--;
		//cout<<"path=\n";
		//for(int i=0;i<=index;i++) cout<<path[i]<<" ";
		//cout<<endl;

		if(type==1)
		{
			for(int i=0;i<=index/2;i++)
			{
				int vl=val[path[i]];
				val[path[i]]=val[path[index-i]];
				val[path[index-i]]=vl;
			}
			//cout<<"values=\n";
			//for(int i=1;i<=n;i++) cout<<val[i]<<" ";
			//	cout<<endl;
		}
		else
		{
			scanf("%d%d",&vl,&vr);
			indexu=0; indexv=0; common=root;
			temp=vl;
			while(temp!=0)
			{
				pathu[indexu++]=temp;
				temp=pred[temp];
			}
			//for(int i=0;i<indexu;i++) cout<<pathu[i]<<" ";
			//cout<<endl;

			temp=vr;
			while(temp!=0)
			{
				pathv[indexv++]=temp;
				temp=pred[temp];
			}
			//for(int i=0;i<indexv;i++) cout<<pathv[i]<<" ";
			//cout<<endl;

			tempindexu=indexu-1; tempindexv=indexv-1;
			while(true)
			{
				if(tempindexu>=0 && tempindexv>=0)
				{
					if(pathu[tempindexu]==pathv[tempindexv])
					{
						common=pathu[tempindexu];
					}
					else 
					{
						tempindexu++;
						break;
					}
					tempindexu--; tempindexv--;
				}
				else 
				{
					tempindexu++;
					break;
				}
			}
			//cout<<"common= "<<common<<endl;
			index2=0;
			/*if(tempindexu<0 || tempindexv<0)
			{
				if(tempindexu<0)
				{
					for(int i=tempindexv;i>=0;i--) 
						path[index++]=pathv[i];
				}
				else if(tempindexv<0)
				{
					for(int i=0;i<=tempindexu;i++)
						path[index++]=pathu[i];
				}
				else path[index++]=common;
			}*/
			//else
			{
				for(int i=0;i<=tempindexu;i++)
				{
					path2[index2++]=pathu[i];
				}
				for(int i=tempindexv;i>=0;i--)
				{
					path2[index2++]=pathv[i];
				}
			}
			index2--;

			//for(int i=0;i<=index;i++) cout<<path[i]<<" ";
			//cout<<endl;
			if(type==2)
			{
				int flag=1;
				for(int i=0;i<=index;i++)
				{	
					if(val[path[i]]!=val[path2[i]]) 
					{
						flag=0; break;
					}
				}
				if(flag==1) printf("Yes\n");
				else printf("No\n");
			}
			else if(type==3)
			{
				for(int i=0;i<=index;i++)
				{	
					val[path2[i]]=val[path[i]]; 
				}
			}
			
		}
	}
	return 0;
}