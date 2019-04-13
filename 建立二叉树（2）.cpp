/* ������ڵ���
   ��ÿһ������Ϊ ���ڵ� ��ڵ� �ҽڵ� 
   �սڵ���*��ʾ
�������룺 7
           ABC
           BDE
           D**
           E**
           CFG
           F**
           G**
    ����� ABDECFG
*/ 
#include<stdio.h>
#include<stdlib.h>
typedef struct BTNode{
	char data;
	struct BTNode *lchild,*rchild;
}BTNode;
 
BTNode **TT=NULL;//����ҵ��Ľڵ�ĵ�ַ 
void find(BTNode **T,char a){
	if(*T)
		if((*T)->data==a)TT=&(*T);
		else
		{
			find(&(*T)->lchild,a);
			find(&(*T)->rchild,a);
	    }
	return ;
}

void add(BTNode **T,char a,char b,char c){  //ͨ�������ı�ʵ�ε�ֵ������ָ��/��ַ �����ṹ���������Ҫָ��ڵ��ָ�� �����ö���ָ�� 
	find(&(*T),a);
	if(b=='*')(*TT)->lchild=NULL;
	else 
	{
		(*TT)->lchild=(BTNode *)malloc(sizeof(BTNode));
		(*TT)->lchild->data=b;
		(*TT)->lchild->lchild=NULL;
		(*TT)->lchild->rchild=NULL;
	}
	if(c=='*')(*TT)->rchild=NULL;
	else
	{
		(*TT)->rchild=(BTNode *)malloc(sizeof(BTNode));
		(*TT)->rchild->data=c;
		(*TT)->rchild->rchild=NULL;
		(*TT)->rchild->lchild=NULL;
	}
}
void visit(BTNode *T){
	printf("%c",T->data);
}
void PreOrderTraverse(BTNode *T){
	if(T)
	{
		visit(T);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
	return ;
}
int main(){
	int n;
	scanf("%d",&n);
	scanf("*[^\n]");scanf("%*c");
	BTNode *Tree=(BTNode *)malloc(sizeof(BTNode));
	char a,b,c;
	scanf("%c%c%c",&a,&b,&c);
	scanf("*[^\n]");scanf("%*c");
	Tree->data=a;             
	if(b=='*')Tree->lchild=NULL;            //�״�������Ǹ��ڵ� ����Ҫ���� 
	else 
	{
		Tree->lchild=(BTNode *)malloc(sizeof(BTNode));
		Tree->lchild->data=b;
		Tree->lchild->lchild=NULL;
		Tree->lchild->rchild=NULL;
	}
	if(c=='*')Tree->rchild=NULL;
	else
	{
		Tree->rchild=(BTNode *)malloc(sizeof(BTNode));
		Tree->rchild->data=c;
		Tree->rchild->lchild=NULL;
		Tree->rchild->rchild=NULL;
	}
	for(int i=1;i<=n-1;i++)
	{
		
		scanf("%c%c%c",&a,&b,&c);
		scanf("*[^\n]");scanf("%*c");
		add(&Tree,a,b,c);
	}
	PreOrderTraverse(Tree);
	return 0;
}
