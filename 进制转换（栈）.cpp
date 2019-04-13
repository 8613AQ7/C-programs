#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h> 
int pow(int a,int b){//快速幂 
	int ans=1;
	int base=a;
	while(b){
		if(b&1)ans*=base;
		base*=base;
		b>>=1;
	}
	return ans;
}

typedef struct linestack{
	int elem;
	struct linestack * next;
}linestack;

linestack * push(linestack *stack,int a){ //压栈 
	linestack *neww=(linestack*)malloc(sizeof(linestack));
	neww->elem=a;
	neww->next=stack;
	stack=neww;
	return stack; 
}
linestack * pop(linestack *stack){ //弹栈 
	linestack* p=stack;
	int temp=p->elem ;
	if(temp>=0&&temp<=9)
	printf("%c",temp+48);
	else printf("%c",temp+55);
	stack=stack->next;
	free(p);
	return stack ;
	
}
int into10(char *c,int system){ //转成十进制 
	int ans=0;
	int k=strlen(c)-1;
	for(int i=0;i<=k;i++){
		char temp=c[i];
		
		if(temp>=48&&temp<=57)
		   {if((temp-48)>=system){
		   	printf("Error!!");
			   return 0; 
		   }
		  ans+=(temp-48)*pow(system,k-i); }
		else ans+=(temp-55)*pow(system,k-i);
	}
//	printf("%d",ans);
	return ans;
}



int main(){
	system("title 进制转换器");
 	system("color 1E");
	char c[20];
	printf("输入你要转换的数字：");
	scanf("%s",c);
	int system;
	printf("输入该数字的进制：");
	scanf("%d",&system);
    int system10=into10(c,system);
    printf("输入你需要得到的进制：") ;
    int outsystem;
	scanf("%d",&outsystem);
	linestack * stack=NULL;
	while(system10/outsystem){
		stack=push(stack,system10%outsystem);
		system10/=outsystem;   
	} 
    stack=push(stack,system10%outsystem);
    printf("结果为：");
    while(stack!=NULL)
	stack=pop(stack);
    
}
