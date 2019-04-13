#include<stdio.h>
#include<stdlib.h>
typedef struct LINK{
	char c;
	struct LINK *next;
}link;

link *initlink(){
	link *head=(link *)malloc(sizeof(link));//光标移动到头节点（首元节点之前 不存放数据） 
	link *tail=head;//光标移动到尾节点 
	link *cur=head;
	char cc;
	while(1){
		scanf("%c",&cc);
		if(cc =='\n')break;
		if(cc =='['){
		cur=head;
		continue;
	}
		if(cc ==']'){
			cur=tail;
			continue;
		}
		link *temp=(link *)malloc(sizeof(link));
		temp->c =cc;
		temp->next=NULL;
		if(cur!=tail){
			temp->next =cur->next;
			cur->next =temp;
			cur=temp; 
		}else{
		cur->next=temp;
		cur=temp;
		tail=temp;
	}
	}
	//head=head->next;
	return head;
}
void print(link *head){
	link *temp=head->next ;
	do{
		printf("%c",temp->c);
		temp=temp->next;
	}while(temp!=0);
}
int main(){
	link *head=initlink();
	
    print(head);

}
