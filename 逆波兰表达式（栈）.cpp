#include<stdio.h>
#include<string.h>//strlen
#include<stdlib.h>//atof
#include<ctype.h>//memset
int top=-1;//栈顶 
void push(float *a,float number){//压栈 
	a[++top]=number;
	return;
}
float pop(float *a){//弹栈 
	float number=a[top--];
	a[top+1]=0; //释放上一个元素 
	return number;
}
int main(){
	float a[50];//栈 
	char bolan[40];//输入的逆波兰表达式 
	char buffer[20];//缓冲区 读取数字 
	int cur=0;//缓冲区光标 
	float num1,num2;//弹栈计算时的临时变量 
	scanf("%[^\n]",bolan);//一次性读取逆波兰表达式 
	scanf("%*[^\n]");scanf("%*c");//清空缓冲区 
	int lenth=strlen(bolan);// 计算表达式长度 开始循环读取 
	for(int i=0;i<lenth;i++){
		char c=bolan[i];//存放每一次读取的字符 
		if(isdigit(c)||c=='.'){ //如果是数字或小数点 放入缓冲区 
			buffer[cur++]=c;
			//buffer[cur]='\0';
		}else 
		if(c==32){ //如果是空格 将缓冲区的所有字符幻化为数字压栈  
		if(isdigit(buffer[0])){//有可能是字符后的空格 不作处理 
			push(a,atof(buffer));
			cur=0;
			memset(buffer,'\0',strlen(buffer)*sizeof(char));}
   //         printf("push:%f\n",atof(buffer));
		}else
		switch(c){//如果是符号 从栈中弹出两个数字 进行计算并压栈 
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
				if(num1==0){//除数为0 输入错误 
				printf("输入错误！");return 0; }
				push(a,num2/num1);
		    ;break;
		    default:printf("输入错误！");return 0;break;//若以上字符都没有出现 即用户输入错误 直接结束程序 
	        }
		}
		//print(a);
    }
	float ans=pop(a);//最后一个栈中的元素即是所求答案 直接输出 
	printf("ans is:%.2f",ans);
	return 0; 
}
