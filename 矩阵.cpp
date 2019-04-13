//c++数组与标准库vector都没有很好地支持矩阵 
#include<iostream>
#include<vector>
#define N 4		//矩阵为 N*N 型 
using namespace std;

class array:public  vector< vector< int > >
{

public: array(int p[N][N]);		
		void show();
		array T();	//转置 
		array inv();	//逆矩阵 
		array operator+(const array &A) const;
		array operator-(const array &A) const;
		array operator*(const array &A) const;
};

array::array(int p[N][N])		//初始化 vector的初始化比较鸡肋 为数组指针的头尾 而每一个元素又是一个数组 顾用较简便c++的数组初始化再转换 
{
	for(int i=0;i<N;i++)
		{
			vector<int> x(p[i],p[i]+N);
			this->push_back(x);
		}
}

void array::show() //输出矩阵 
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cout<<(*this)[i][j]<<' ';   // this->array->row->column
		}
		cout<<endl;
	}
	cout<<endl;
}

array array :: T()
{
	int a[N][N];
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			a[i][j]=(*this)[j][i];
		}
	}
	array TT(a);
	return TT ;
}
array array :: operator+(const array &A) const	//定义矩阵加法 
{
	int T[N][N];
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			T[i][j]=(*this)[i][j]+A[i][j];
		}
	}
	array TT(T);
	return TT ;
}

array array :: operator-(const array &A) const  //定义矩阵减法 
{
	int T[N][N];
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			T[i][j]=(*this)[i][j]-A[i][j];
		}
	}
	array TT(T);
	return TT ;
}

array array :: operator*(const array &A) const  //定义矩阵乘法 
{
	int T[N][N];
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			int s=0;
			for(int m=0;m<N;m++)
			{
				s+=(*this)[i][m]*A[m][j];
			} 
			T[i][j]=s;
		}
	}
	array TT(T);
	return TT ;
}

int main()
{
	int b1[N][N]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	array a1(b1);
	cout<<"a1:"<<endl;
	a1.show();
	int b2[N][N]={{11,22,33,44},{55,66,77,88},{99,101,111,122},{133,214,315,716}};
	array a2(b2);
	cout<<"a2:"<<endl;
	a2.show();
	array a3=a1+a2;
	cout<<"a1+a2:"<<endl;
	a3.show();
	a3=a1-a2;
	cout<<"a1-a2:"<<endl;
	a3.show();
	a3=a1*a2;
	cout<<"a1*a2:"<<endl;
	a3.show();
	a3=a1.T();
	cout<<"a1.T:"<<endl;
	a3.show();
}
