#include<stdio.h>
#include<string.h>//strlen
#include<stdlib.h>//atof
#include<ctype.h>//memset
int top=-1;//ջ�� 
void push(float *a,float number){//ѹջ 
	a[++top]=number;
	return;
}
float pop(float *a){//��ջ 
	float number=a[top--];
	a[top+1]=0; //�ͷ���һ��Ԫ�� 
	return number;
}
int main(){
	float a[50];//ջ 
	char bolan[40];//������沨�����ʽ 
	char buffer[20];//������ ��ȡ���� 
	int cur=0;//��������� 
	float num1,num2;//��ջ����ʱ����ʱ���� 
	scanf("%[^\n]",bolan);//һ���Զ�ȡ�沨�����ʽ 
	scanf("%*[^\n]");scanf("%*c");//��ջ����� 
	int lenth=strlen(bolan);// ������ʽ���� ��ʼѭ����ȡ 
	for(int i=0;i<lenth;i++){
		char c=bolan[i];//���ÿһ�ζ�ȡ���ַ� 
		if(isdigit(c)||c=='.'){ //��������ֻ�С���� ���뻺���� 
			buffer[cur++]=c;
			//buffer[cur]='\0';
		}else 
		if(c==32){ //����ǿո� ���������������ַ��û�Ϊ����ѹջ  
		if(isdigit(buffer[0])){//�п������ַ���Ŀո� �������� 
			push(a,atof(buffer));
			cur=0;
			memset(buffer,'\0',strlen(buffer)*sizeof(char));}
   //         printf("push:%f\n",atof(buffer));
		}else
		switch(c){//����Ƿ��� ��ջ�е����������� ���м��㲢ѹջ 
			case 43:{
				num1=pop(a);
				num2=pop(a);
				push(a,num2+num1);
//printf("pop:%f %f\n",num1,num2);
			};break;
		    case 45:{
		    	num1=pop(a);
				num2=pop(a);
				push(a,num2-num1);

		    };break;
		    case 42:{
		    	num1=pop(a);
				num2=pop(a);
				push(a,num2*num1);
		    };break;
		    case 47:{
		    	num1=pop(a);
				num2=pop(a);
				if(num1==0){//����Ϊ0 ������� 
				printf("�������");return 0; }
				push(a,num2/num1);
		    ;break;
		    default:printf("�������");return 0;break;//�������ַ���û�г��� ���û�������� ֱ�ӽ������� 
	        }
		}
		//print(a);
    }
	float ans=pop(a);//���һ��ջ�е�Ԫ�ؼ�������� ֱ����� 
	printf("ans is:%.2f",ans);
	return 0; 
}
