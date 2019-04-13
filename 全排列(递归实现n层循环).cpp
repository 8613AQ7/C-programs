#include<iostream>
#include<algorithm>
using namespace std;

bool examAnswer(int n, int *A)		//�����Ƿ�Ϊȫ����  
{
	int exam[n];
	for(int i = 0; i < n; i++)		//Ϊ���ı�ԭ����Ӱ��֮���ö�� ����һ�����ڼ��� 
	{
		exam[i] = A[i];
	}
	sort(exam, exam+n);				 
	for(int i = 0 ; i < n;i++)		//��������������ֶ�Ӧ 
	{
		if(exam[i] != i + 1)
		{
			return false;
		}
	}
	return true;
}

void f(int n, int cursor, int *A, int &count)	//n��ѭ�� ʹ�õݹ鷽��ʵ��  
{
	if(cursor == n )							//cursor���Ƶݹ���� 
	{	
		bool correct = examAnswer(n, A);		//�������ȷ��ֱ����� 
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
			A[cursor] = i;						//ʹ��һά����洢 ֮�󸲸� 
			f(n, cursor + 1, A, count);			//�����²�ѭ�� 
		}
		
	}
	
}

int main()
{
	int n;
	cin>>n;
	int A[n];
	int count = 0; 
	f(n, 0, A, count);	//��ʼn��ѭ�� 
	cout<<"��"<<count<<"��"; 
}
