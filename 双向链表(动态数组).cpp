#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

typedef struct Link{//����ÿ���ڵ����� 
    struct Link *prior;//˫������ 
	int num;
	struct Link *next;
}link;

link *print(link *head){//������� 
 	link *temp=head;
 	link *temp2=NULL;//���ڷ������ 
 	printf("˳��");
	 while(temp!=NULL){
 		printf("%-4d ",temp->num);
 			if(temp->next==NULL)temp2=temp;
 		temp=temp->next;
 	}
 	printf("\n");
 	//������� 
 	printf("����");
	 while(temp2!=NULL){
 		printf("%-4d ",temp2->num );
 		temp2=temp2->prior ;
 	}
 	printf("\n");
 }
 
 link *initlink(void){//�������� 
 	link *head=(link *)malloc(sizeof(link));
 	link *temp=head;
    /*�س���ֻ����%c��ȡ������ÿ�ζ��ȶ�ȡһ���ַ�ʱ����Ӱ�����ֵĶ�ȡ
	  ���򿪱�һ���㹻����ַ����飬�����ַ���ȡ���������� �ո���س���
	  ÿ��⵽һ���ո�ʱ��' '��ascii==32�� ���ַ�����ת�������֣�����ֻ�����֣���������� ������һ�ζ�ȡ*/
	char *s=(char *)malloc(50*sizeof(char)); 
	//char s[30]={0};
 	int num;
 	int i=0;
 	    while(1){
 	    scanf("%c",&s[i]);
        if(s[i]=='\n'){
        	num=atoi(s);
        	link *neww=(link *)malloc(sizeof(link));
 		neww->num =num;
 		neww->next =NULL;
 		neww->prior=temp;
 		temp->next =neww;
 		temp=neww;
 		break;
        }
        if(s[i]==32){
  	        num=atoi(s);
            memset(s,0,sizeof(s));
             i=-1;
        link *neww=(link *)malloc(sizeof(link));
 		neww->num =num;
 		neww->next =NULL;
 		neww->prior=temp;//˫������ 
 		temp->next =neww;
 		temp=neww;
  
  }
  i++;
}
	 	
 	
    head=head->next ;
	head->prior =NULL;
    print(head);
	free(s);//�ͷ�Ϊ֮ǰ��ֵ�����ٵ��ַ����� 
    return head;
 }
 
 
 
 link *exchange(link *head,int a,int num){//�ı�ĳһ�ڵ��ֵ 
 	link *temp=head;
 	    for(int i=1;i<a;i++)
 	    	temp=temp->next ;
 	    temp->num =num;
 	    print(head);
 	    return head ;
 }
 
 link *add(link *head,int a,int num){//����һ���½ڵ� 
 	link *temp=head;

 	for(int i=1;i<a;i++)
 	   temp=temp->next ;
 	link *addd=(link *)malloc(sizeof(link));
 	addd->num =num;
	 if(temp->next ==NULL){
	 	addd->next =NULL;
	 }else{
	 	addd->next =temp->next ;
	 	addd->next->prior =addd;
	 }
 	
 	addd->prior =temp;
 	temp->next =addd;
 	
 	print(head);
 	return head;
 }
 
 link *delet(link *head,int a){//ɾȥһ���ڵ� 
     link *temp=head; 
    if(a==1){
    	link *del=temp;
		temp=temp->next ;
    	temp->prior =NULL;
    	head=temp;
    	free(del);
    }else{
 	for(int i=1;i<a-1;i++)
 	    temp=temp->next;
 	    link *del=temp->next ;
	 temp->next=temp->next->next ;
	 temp->next ->prior=temp;
	free(del);
}
	print(head);
	return head;
 }
 int main(){ 
 	system("title ˫������");
 	system("color 1E");
 //	int n;
 //	printf("��xλ����");
 	//scanf("%d",&n);
	  printf("�������ݲ��Իس���������"); 
	 link *head=initlink();
 	int a,num;
 	printf("�ı��xλΪy��");
 	scanf("%d %d",&a,&num);
 	exchange(head,a,num);
 	printf("�ڵ�xλ�����y��");
 	scanf("%d %d",&a,&num); 
 	add(head,a,num);
    printf("ɾȥ��x������");
    scanf("%d",&a); 
    delet(head,a);
 }
