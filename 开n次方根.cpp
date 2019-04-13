//��n�η������ⷽ�̽����棩 ţ�ٵ����� 
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#define trytime 30
#define estimate 1e-6
double quickpow(double x,int y){ //������ 
	double ans=1,base=x;
	while(y)
	{
		if(y&1)ans*=base;
		base*=base;
		y>>=1;
	}
	return ans;
}

int flag=1;  //�����������֮��Ĵ��� 
double extraction(double x0,double a ,double n){
	double x=x0;
	flag=1;
	do
	{
		x0=x;
		x=(n-1)*x0+a/quickpow(x0,n-1);
		x=x*1.0/n;
		if(!isnormal(x))
		{
			flag=0;
			break;
		}
	}while(fabs(x-x0)>estimate);
	return x;
}
int main(){
	double a;
	int n;
	scanf("%lf %d",&a,&n);
	if(a<0&&!(n&1)||n<=0)   //�ݲ�֧�ָ����η� 
	{
	printf("����");
	return 0;
	}
	double ans,temp;
	srand((unsigned)time(NULL));
	for(int i=1;i<=trytime;i++)        //�����������֮��Ĵ��� ���ѡȡ��ʼֵ���е��� 
	{
		temp=extraction(rand()%10-5,a,n);
		if(flag)ans=temp;
	}
	printf("%.4lf",ans);
	if(a>0&&!(n&1))printf("\n%.4lf",-ans);
	return 0;
}
