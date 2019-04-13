#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#define N 100000
using namespace std;
int  s[N+1][20];
void build(int n,int k)
{
	for(int i=1;i<=k;i++)
	{
		for(int  j=1;j<=n;j++)
			if(j+(1<<i)-1<=n)
			{
				s[j][i] = min(s[j][i-1],s[j+(1<<(i-1))][i-1]);
			}
	}
	
}
int query(int a, int b)
{
	int  w = b-a+1;
	int  k = floor(log(w)/log(2));
	return min(s[a][k],s[b-(1<<k)+1][k]);
}


int main()
{
	
	int n,m;
	cin>>n>>m;
	int k = floor(log(n)/log(2));
	memset(s,0x3f,sizeof(s));
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][0];
	}
	build(n,k);
	for(int i=1;i<=m;i++)
	{
		int a,b;
		cin>>a>>b;
		cout<<query(a,b);
	}
}
