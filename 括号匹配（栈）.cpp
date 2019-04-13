#include<stdio.h>
int top=-1;
	char a[255];
void push(){
	a[++top]='(';
}
void pop(){
	if(top==-1)return;
	top--;
}

int main(){
	char c;

    while(1){
    	scanf("%c",&c);
    	if(c=='@')break;
    	if(c=='(') push();
    	if(c==')'){
		   if(a[top]=='(')pop();
		   else {
		   printf("No");
		   return 0;}
	}
}   if(top==-1)printf("Yes");
     else printf("No");
}
