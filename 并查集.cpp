#include<iostream>

#define N 10001
using namespace std;
int f[N];//¸¸½Úµã 
int find(int x)
{
	if(f[x] == x)
	{
		return x;
	}
	else
	{
		return f[x]=find(f[x]);
	}
} 
void make(int x)
{
	f[x] = x;
	return;
}
void link(int x,int y)
{
	f[find(x)] = find(y);
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		make(i);
	} 
	for(int i = 0;i<m;i++)
	{
		int op,n1,n2;
		cin>>op>>n1>>n2;
		if(op==1)
		{
			link(n1,n2);
		}
		else
		{
			if(find(n1)==find(n2))
			{
				cout<<"Y"<<endl;
			}
			else
			{
				cout<<"N"<<endl;
			}
		}
	} 
	return 0;
}
