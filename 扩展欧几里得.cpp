#include <iostream>
/*
	求解 	ax + by = gcd(a,b) 即最大公约数
	先找到  bx0 + (a mod b)y0 = gcd(b, a mod b)
	可知  ax + by = bx0 + (a- a/b * b ) y0
	整理找到一组解 即 x = y0
	                  y = x0 - (a/b)y0
	得到递推公式
	
	终止条件为 b = 0 即 ax + 0y = gcd(a,0) = 0           任何数与0的最大公约数为其本身 
	求得x = 1 y可取任意值 
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
    exgcd(b,a%b,x,y);//返回上一组x0 y0 
    int k=x;
    x=y;
    y=k-a/b*y;		//更新x y 
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
