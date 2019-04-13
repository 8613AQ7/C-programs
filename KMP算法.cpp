#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void initnext(int *next,char* T){
	next[1]=0;
	next[2]=1;
	for(int i=3;i<=next[0];i++){
		int j=i-1;
		while(1){
		     if(T[next[j]-1]==T[i-2]){
		     	next[i]=next[j]+1;
		     	break;
		     }else 
			    j=next[j];
			 if(j==0){
			 	next[i]=1;
			 	break;
			 }
		}
	}
	return ;
} 

int KMP(char *S,char* T){
	int next[strlen(T)];
	next[0]=strlen(T);
	initnext(next,T);
    int flag=0;
    int i=1,j=1;
	while(i<=strlen(S)&&j<=next[0]){
		    if(j==0||S[i-1]==T[j-1]){
		    	i++;
		    	j++;
		    }else
		        j=next[j];
		    if(j>next[0]){
		    	flag=i-next[0];
		    	break;
		    }
		}
    return flag;
}

int main(){
	char *S=(char*)malloc(200*sizeof(char));
	scanf("%s",S);
	realloc(S,strlen(S)*sizeof(char));
	char *T=(char*)malloc(20*sizeof(char));
	scanf("%s",T);
	realloc(T,strlen(T)*sizeof(char));
	int flag=KMP(S,T);
	if(flag)printf("第%d位",flag);
	else printf("没有"); 
}
