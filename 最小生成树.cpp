#include<iostream>
#include<queue>
#include<algorithm>
#define M 200001
#define N 5001 
using namespace std;

struct node 
{
	int u,v,w;
}e[M];

bool cmp (const node &a,const node &b)
{
	return a.w < b.w;
}
int f[N];

int find(int x)
{
	if(f[x]==x)return x;
	else return f[x]=find(f[x]);
}

int link(int x,int y)
{
	if(find(x)==find(y))return 0;
	else
	{
		f[find(x)]=find(y);
		return 1;
	}
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
	} 
	for(int i=1;i<=m;i++)
	{
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	sort(e+1,e+1+m,cmp);
	int ans = 0;
	for(int i=1;i<=m;i++)
	{
		if(link(e[i].u,e[i].v))
		{
			ans+=e[i].w;
		}
	}
	cout<<ans;
}
