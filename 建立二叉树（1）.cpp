/*��ǰ��������� �սڵ���*��ʾ
�������룺 ABD**E**CF**G**
    ����� ABDECFG
*/ 

#include<stdio.h>
#include<stdlib.h>
typedef struct BTNode{
	char data;
	struct BTNode *lchild,*rchild;
}BTNode;

void CreatTree(BTNode ** T){
	char c;
	scanf("%c",&c);
	if(c=='*')
	{
		*T=NULL;
	}else
	{
		*T=(BTNode *)malloc(sizeof(BTNode));
		(*T)->data=c;      
		CreatTree(&(*T)->lchild);
		CreatTree(&(*T)->rchild);
	}
	return ;
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
	return;
}
int main(){
	BTNode *Tree=NULL;
	CreatTree(&Tree);
	PreOrderTraverse(Tree);
	return 0;
}
