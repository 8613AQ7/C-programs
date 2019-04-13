#include<stdio.h>
#include<stdlib.h>
typedef struct queue{
	int num;
	struct queue *next;
}queue;
queue *initqueue(){
    queue *head=(queue *)malloc(sizeof(queue));
    head->num=1;
    head->next=NULL;
    return head;
}
queue *add(queue *head,int i,int k,int p){
	queue *neww=(queue *)malloc(sizeof(queue));
	neww->num=i;
	neww->next=NULL;
	if(k==1&&p==0){
		neww->next =head->next ;
		head->next =NULL;
	}else{
	      queue *temp=head;
          for(int j=1;j<k-1;i++)
	          temp=temp->next;
	      if(temp->next->next =NULL&&p==1){
	        temp->next->next =neww;
	     }else{
	          if(p==1)temp=temp->next;
	           neww->next=temp->next->next;
	           temp->next=neww;
	   	} 
		    }
	return head;
}
void print(queue *head){
	queue *temp=head;
	while(temp!=NULL)
	{
		printf("%d ",temp->num );
		temp=temp->next ;
	}
}
int main(){
	int n;
	scanf("%d",&n);
	queue *head=initqueue();
//	printf("%d",head->num);
	int k,p;
	for(int i=2;i<=n;i++){
		scanf("%d %d",&k,&p);
		head=add(head,i,k,p);
	}
	print(head);
}
