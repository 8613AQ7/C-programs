#include <iostream>
/*
	��� 	ax + by = gcd(a,b) �����Լ��
	���ҵ�  bx0 + (a mod b)y0 = gcd(b, a mod b)
	��֪  ax + by = bx0 + (a- a/b * b ) y0
	�����ҵ�һ��� �� x = y0
	                  y = x0 - (a/b)y0
	�õ����ƹ�ʽ
	
	��ֹ����Ϊ b = 0 �� ax + 0y = gcd(a,0) = 0           �κ�����0�����Լ��Ϊ�䱾�� 
	���x = 1 y��ȡ����ֵ 
*/  
using namespace std;

void exgcd(int a,int b,int &x,int &y)
{
    if( a % b ==0)
    {
        x = b;
        y = 1-a;
        return;
    }
    exgcd(b,a%b,x,y);//������һ��x0 y0 
    int k=x;
    x=y;
    y=k-a/b*y;		//����x y 
    return;
}
int main()
{
	int x,y;
	int a,b;
    cin>>a>>b;
    exgcd(a,b,x,y);
    cout<<x<<" "<<y;
}
