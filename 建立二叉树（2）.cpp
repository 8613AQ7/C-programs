/* 先输入节点数
   后每一次输入为 根节点 左节点 右节点 
   空节点用*表示
例：输入： 7
           ABC
           BDE
           D**
           E**
           CFG
           F**
           G**
    输出： ABDECFG
*/ 
#include<stdio.h>
#include<stdlib.h>
typedef struct BTNode{
	char data;
	struct BTNode *lchild,*rchild;
}BTNode;
 
BTNode **TT=NULL;//存放找到的节点的地址 
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

void add(BTNode **T,char a,char b,char c){  //通过函数改变实参的值必须用指针/地址 而树结构本身就是需要指向节点的指针 所以用二级指针 
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
	if(b=='*')Tree->lchild=NULL;            //首次输入的是根节点 不需要查找 
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
