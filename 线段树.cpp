/*
	�����޸� 
	�����޸� 
	�����ѯ 

*/

#include<iostream>
using namespace std;
#define ls (i << 1)
#define rs (i << 1 | 1) 

struct node
{
	long long l,r,m,w; //���Ҷ˽� �е� ������ 
	long long sum;
	int tag; 
}tree[400001];
int value[100001];

void update(long long i)
{
	tree[i].sum = tree[ls].sum + tree[rs].sum;
}


void down(long long i)	//����´� 
{
	if(tree[i].tag > 0)
	{
		tree[ls].tag = tree[i].tag;		//�´���ǲ��޸�����������sum 
		tree[rs].tag = tree[i].tag;
		tree[i].tag = 0;
		
		tree[ls].sum = tree[ls].w * tree[ls].tag;
		tree[rs].sum = tree[rs].w * tree[rs].tag;
	}
}

void build(long long i, long long l, long long r)
{
	tree[i].l = l;				//��¼�Ľ��ά�������� 
	tree[i].r = r;
	tree[i].w = r - l + 1;
	tree[i].m = (l + r) >> 1 ; 
	tree[i].tag = 0;
	
	if(l==r)				//Ҷ��� ֹͣ�ݹ� ��¼ֵ 
	{
		tree[i].sum = value[l];
		return;
	}
	else
	{

		build(ls, tree[i].l , tree[i].m);	//������������ 
		build(rs, tree[i].m + 1, tree[i].r);
		update(i);		//��������������������ɺ���������ֵ 
	}
}


long long query(long long i,long long a, long long b)	//�����ѯ 
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

void changeone(long long i, long long pos, int v)	//�����޸� 
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


void changesome(long long i, long long a, long long b, int v)	//�����޸� 
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
