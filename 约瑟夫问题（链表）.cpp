#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

typedef struct Link{//����ÿ���ڵ����� 
	int num;
	struct Link *next;
}link;

 link *initlink(int n){//�������� 
 	link *head=(link *)malloc(sizeof(link));
 	link *temp=head;
    for(int i=1;i<=n;i++){
        link *neww=(link *)malloc(sizeof(link));
 		neww->num =i;
 		neww->next =NULL;
 		temp->next =neww;
 		temp=neww;
        }
    head=head->next ;
    temp->next =head;
    return head;
}

 link *delet(link *head){//ɾȥһ���ڵ� 
        link *temp=head->next ;
		printf("%d ",temp->num );
        head->next=temp->next;
        free(temp);
	return head;
 }
 int main(){ 
	int n,m;
    scanf("%d %d",&n,&m);
    link *head=initlink(n);

    int left=n;
    int count=1;

 	while(left){
 		 while(count<m-1){
 		 head=head->next ;
		 count++;
		 }
 		link *newhead=delet(head);
 		count=0;
 		left--;
 		head=newhead;
 	}
 }
