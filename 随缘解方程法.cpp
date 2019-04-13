/*牛顿迭代法解一元高次方程 
	在函数上选取一点x0,寻找一点x比x0更接近于根，用x替代x0，重复操作
 	过点（x0,f(x0)）的切线方程为（f(x)-f(x0)）=f'(x)(x-x0)
	整理得：x=x0-f(x0)/f'(x0)  即为牛顿迭代法公式 
*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#define trytime 2000   //多次随机初始值  尽量找到更多解 
#define astimate 1e-6  //精确程度 
int flag[trytime];
double pow(double x,int y){  //计算乘方 
	if(y==0)return 1;
	if(y==1)return x;
	if(x==0)return 0;
	double base=x;
	double ans=1;
	while(y)
	{
	   if(y&1)ans*=base;
	   base*=base;
	   y>>=1;
	}
	return ans;
}

double solution(double x,double *a,int degree,int k){
	double x0,fx0=0,f_x0=0;
	do
	{
		x0=x;
		fx0=0;
		f_x0=0;
		for(int i=1;i<=degree+1;i++)
		    fx0+=a[i]*pow(x0,degree-i+1);
		for(int i=1;i<=degree;i++)
			f_x0+=(degree-i+1)*a[i]*pow(x0,degree-i);
			x=x0-fx0/f_x0;
		if(!isnormal(x))flag[k]=0;   	//判断是否发生意料之外的错误 
	}while(fabs(x-x0)>astimate);
	return x;
}
int main(){
	printf("请输入方程最高项次数："); 
	int degree;
	scanf("%d",&degree);
	scanf("%*[^\n]");scanf("%*c");
	printf("请按次数的降序输入系数："); 
	double a[degree+1];
	for(int i=1;i<=degree+1;i++)
		scanf("%lf",a+i);
	double ans[trytime];
	srand((unsigned)time(NULL));
	for(int i=0;i<=trytime;i++) 		//此方法只能找到一个解 故选取多个初始值重复运算得到多个答案
	{ 
		flag[i]=1;                    
		ans[i]=solution(rand()%10000-5000,a,degree,i);
	
	}
	printf("此方程的实数解为：");
	for(int i=1;i<=trytime;i++)                      //筛选答案  两个答案相差小于精确值时 认为它们是相等的 只输出一个 
	    for(int j=0;j<=i-1;j++)
	    	if(fabs(ans[i]-ans[j])<astimate)flag[i]=0;
	for(int i=0;i<=trytime;i++) 
		if(flag[i])printf("\n  %.4lf",ans[i]);
	return 0; 
}
