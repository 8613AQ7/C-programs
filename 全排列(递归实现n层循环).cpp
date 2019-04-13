#include<iostream>
#include<algorithm>
using namespace std;

bool examAnswer(int n, int *A)		//检验是否为全排列  
{
	int exam[n];
	for(int i = 0; i < n; i++)		//为不改变原数组影响之后的枚举 复制一份用于检验 
	{
		exam[i] = A[i];
	}
	sort(exam, exam+n);				 
	for(int i = 0 ; i < n;i++)		//排序后索引与数字对应 
	{
		if(exam[i] != i + 1)
		{
			return false;
		}
	}
	return true;
}

void f(int n, int cursor, int *A, int &count)	//n层循环 使用递归方法实现  
{
	if(cursor == n )							//cursor限制递归层数 
	{	
		bool correct = examAnswer(n, A);		//检验后正确则直接输出 
		if(correct)
		{
			count++;
			for(int i = 0 ; i < n ;i++)
			{
				cout<< A[i];
			}
			cout<<endl;
		}
	}
	else
	{
		for(int i = 1; i <= n; i++)
		{
			A[cursor] = i;						//使用一维数组存储 之后覆盖 
			f(n, cursor + 1, A, count);			//进入下层循环 
		}
		
	}
	
}

int main()
{
	int n;
	cin>>n;
	int A[n];
	int count = 0; 
	f(n, 0, A, count);	//开始n层循环 
	cout<<"共"<<count<<"个"; 
}
