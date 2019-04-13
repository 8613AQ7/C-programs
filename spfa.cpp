#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
#include<fstream>
#define N 100001
#define inf 0x3f3f3f
#define pii pair<int,int>
using namespace std;
vector<vector<pii> > graph(N);
queue<int> q;
int dist[N];
bool inq[N];
void spfa(int s)
{
	memset(dist,63,sizeof(dist));
	memset(inq,0,sizeof(inq));
	dist[s] = 0;
	inq[s] = true;
	q.push(s);
	
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		inq[u] = false;
		
		vector<pii>::iterator it;
		for(it = graph[u].begin();it!=graph[u].end();it++)
		{
			int v = it->second;
			if(dist[v] > dist[u] + it->first)
			{
				dist[v] = dist[u] + it->first;
				if(!inq[v])
				{
					q.push(v);
					inq[v] = true;
				}
			}
		}
	}
}
int main()
{
	int n,m,s;
	cin>>n>>m>>s;
	for(int i = 0;i < m; i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		graph[u].push_back(make_pair(w,v));
	}
	spfa(s);
	for(int i=1;i<=n;i++)
	{
		cout<<dist[i]<<" ";
	}
}
