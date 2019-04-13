#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

typedef struct Link{//定义每个节点类型 
    struct Link *prior;//双向链表 
	int num;
	struct Link *next;
}link;

link *print(link *head){//输出链表 
 	link *temp=head;
 	link *temp2=NULL;//用于反向输出 
 	printf("顺：");
	 while(temp!=NULL){
 		printf("%-4d ",temp->num);
 			if(temp->next==NULL)temp2=temp;
 		temp=temp->next;
 	}
 	printf("\n");
 	//倒着输出 
 	printf("倒：");
	 while(temp2!=NULL){
 		printf("%-4d ",temp2->num );
 		temp2=temp2->prior ;
 	}
 	printf("\n");
 }
 
 link *initlink(void){//生成链表 
 	link *head=(link *)malloc(sizeof(link));
 	link *temp=head;
    /*回车符只能用%c读取，而若每次都先读取一个字符时，会影响数字的读取
	  故向开辟一个足够大的字符数组，皆用字符读取（包括数字 空格与回车）
	  每检测到一个空格时（' '或ascii==32） 将字符数组转换成数字（里面只有数字）并将其清空 进行下一次读取*/
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
 		neww->prior=temp;//双向链表 
 		temp->next =neww;
 		temp=neww;
  
  }
  i++;
}
	 	
 	
    head=head->next ;
	head->prior =NULL;
    print(head);
	free(s);//释放为之前赋值所开辟的字符数组 
    return head;
 }
 
 
 
 link *exchange(link *head,int a,int num){//改变某一节点的值 
 	link *temp=head;
 	    for(int i=1;i<a;i++)
 	    	temp=temp->next ;
 	    temp->num =num;
 	    print(head);
 	    return head ;
 }
 
 link *add(link *head,int a,int num){//加入一个新节点 
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
 
 link *delet(link *head,int a){//删去一个节点 
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
 	system("title 双向链表");
 	system("color 1E");
 //	int n;
 //	printf("共x位数：");
 	//scanf("%d",&n);
	  printf("输入数据并以回车键结束："); 
	 link *head=initlink();
 	int a,num;
 	printf("改变第x位为y：");
 	scanf("%d %d",&a,&num);
 	exchange(head,a,num);
 	printf("在第x位后加入y：");
 	scanf("%d %d",&a,&num); 
 	add(head,a,num);
    printf("删去第x个数：");
    scanf("%d",&a); 
    delet(head,a);
 }
