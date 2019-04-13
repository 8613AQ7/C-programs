#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
#define N 1000000

int main()
{
	long long n;
	cin>>n;
	int flag[n+1];
	long long prime[n+1];
	//long long phi[n+1];
	memset(flag,0,sizeof(flag));
	int count = 0;
	for(long long i = 2;i <= n;i++)
	{
		if(!flag[i])
		{
			prime[++count] = i;
	//		phi[i] = i - 1;	//p������ phi(p) = p - 1 
		}
		
		for(long long j = 1;j <= count && i * prime[j] <= n;j++)
		{
			flag[i * prime[j]] = 1;
			if(i % prime[j] == 0)
			{
	//			phi[i * prime[j]] = phi[i] * prime[j];		//p������ phi(p^a)=(p-1)phi(p^(a-1)) 
				break;		//��ֻ֤����С������ɸһ�� 
			}
			else
			{
	//			phi[i * prime[j]] = phi[i] * (prime[j] - 1);	//��m n ���� phi(mn)=phi(m)phi(n) 
			}
		
		}
	}
	ofstream f("prime.out");
	f<<prime[1];
	for(long long i =count-100;i<=count;i++)
	{
		f<<","<<prime[i];
	}
	/*
	f<<"\n"<<phi[2];
	for(long long i = 3;i<=n;i++)
	{
		f<<","<<phi[i];
	}*/
	f.close();
}
