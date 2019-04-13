/*
	单点修改 
	区间修改 
	区间查询 

*/

#include<iostream>
using namespace std;
#define ls (i << 1)
#define rs (i << 1 | 1) 

struct node
{
	long long l,r,m,w; //左右端界 中点 区间宽度 
	long long sum;
	int tag; 
}tree[400001];
int value[100001];

void update(long long i)
{
	tree[i].sum = tree[ls].sum + tree[rs].sum;
}


void down(long long i)	//标记下传 
{
	if(tree[i].tag > 0)
	{
		tree[ls].tag = tree[i].tag;		//下传标记并修改左右子树的sum 
		tree[rs].tag = tree[i].tag;
		tree[i].tag = 0;
		
		tree[ls].sum = tree[ls].w * tree[ls].tag;
		tree[rs].sum = tree[rs].w * tree[rs].tag;
	}
}

void build(long long i, long long l, long long r)
{
	tree[i].l = l;				//记录改结点维护的区间 
	tree[i].r = r;
	tree[i].w = r - l + 1;
	tree[i].m = (l + r) >> 1 ; 
	tree[i].tag = 0;
	
	if(l==r)				//叶结点 停止递归 记录值 
	{
		tree[i].sum = value[l];
		return;
	}
	else
	{

		build(ls, tree[i].l , tree[i].m);	//构建左右子树 
		build(rs, tree[i].m + 1, tree[i].r);
		update(i);		//左子树与右子树构建完成后更新自身的值 
	}
}


long long query(long long i,long long a, long long b)	//区间查询 
{
		
	if(a <= tree[i].l && tree[i].r <= b)
	{
		return tree[i].sum;
	}
	else
	{
		down(i);
		long long sum = 0;
		if( a <= tree[i].m)
		{
			sum += query(ls, a, b);
		}
		if( b > tree[i].m)
		{
			sum += query(rs, a, b);
		}
		return sum;
	}
}

void changeone(long long i, long long pos, int v)	//单点修改 
{
	if(tree[i].l == tree[i].r)
	{
		tree[i].sum = v;
		return;
	}
	else
	{
		if(pos <= tree[i].m)
		{
			changeone(ls, pos, v);
		}
		else
		{
			changeone(rs,pos, v);
		}
		update(i);
	}
}


void changesome(long long i, long long a, long long b, int v)	//区间修改 
{
	
	if(a <= tree[i].l && tree[i].r <= b)
	{
		tree[i].tag = v;
		tree[i].sum = tree[i].w * v;
		return;
	}
	else
	{
		down(i);
		if( a <= tree[i].m)
		{
			changesome(ls,a,b,v);
		}
		if( b > tree[i].m)
		{
			changesome(rs,a,b,v);
		}
		update(i);
	}
}
void print(long long n)
{
	for(int i = 1;i <= 4*n;i++)
	{
		cout<<i<<" "<<tree[i].l<<" "<<tree[i].r<<" "<<tree[i].sum<<endl;
	}
}


int main()
{
	long long n;
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> value[i];
	}
	build(1,1,n);
	
	changesome(1,2,3,2);
	long long a,b;
	while(cin >> a >> b)
	cout << query(1, a, b);
	
}
