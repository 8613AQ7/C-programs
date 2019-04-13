/*ţ�ٵ�������һԪ�ߴη��� 
	�ں�����ѡȡһ��x0,Ѱ��һ��x��x0���ӽ��ڸ�����x���x0���ظ�����
 	���㣨x0,f(x0)�������߷���Ϊ��f(x)-f(x0)��=f'(x)(x-x0)
	����ã�x=x0-f(x0)/f'(x0)  ��Ϊţ�ٵ�������ʽ 
*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#define trytime 2000   //��������ʼֵ  �����ҵ������ 
#define astimate 1e-6  //��ȷ�̶� 
int flag[trytime];
double pow(double x,int y){  //����˷� 
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
		if(!isnormal(x))flag[k]=0;   	//�ж��Ƿ�������֮��Ĵ��� 
	}while(fabs(x-x0)>astimate);
	return x;
}
int main(){
	printf("�����뷽������������"); 
	int degree;
	scanf("%d",&degree);
	scanf("%*[^\n]");scanf("%*c");
	printf("�밴�����Ľ�������ϵ����"); 
	double a[degree+1];
	for(int i=1;i<=degree+1;i++)
		scanf("%lf",a+i);
	double ans[trytime];
	srand((unsigned)time(NULL));
	for(int i=0;i<=trytime;i++) 		//�˷���ֻ���ҵ�һ���� ��ѡȡ�����ʼֵ�ظ�����õ������
	{ 
		flag[i]=1;                    
		ans[i]=solution(rand()%10000-5000,a,degree,i);
	
	}
	printf("�˷��̵�ʵ����Ϊ��");
	for(int i=1;i<=trytime;i++)                      //ɸѡ��  ���������С�ھ�ȷֵʱ ��Ϊ��������ȵ� ֻ���һ�� 
	    for(int j=0;j<=i-1;j++)
	    	if(fabs(ans[i]-ans[j])<astimate)flag[i]=0;
	for(int i=0;i<=trytime;i++) 
		if(flag[i])printf("\n  %.4lf",ans[i]);
	return 0; 
}
