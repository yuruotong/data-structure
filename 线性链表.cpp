#include"malloc.h"
typedef struct LNode{
	int data;
	LNode* next;

}LNode,*LinkList;
 bool GetElem_L(LinkList L,int i,int &e){
 	LinkList p=L->next;
	int j=1;
 	while(p&&j<i){
	 p=p->next;
	 ++j;}
	if(!p||j>i)return false;
	e=p->data;
	return true;
 } 
 bool ListInsert_L(LinkList &L,int i,int e){
 	LinkList p=L;
    int j=0;
    while(p&&j<i-1){
    	p=p->next;
    	++j;
    }
    if(!p||j>i-1) return false;
    //--------------------------------------------------------------------
    //以下是重点 
    LinkList s=(LinkList)malloc(sizeof(LNode)); //添加新的节点S 
    s->data=e;
    s->next=p->next;
	p->next=s;
	//--------------------------------------------------------------------- 
	return true; 
    
}
bool ListDelete_L(LinkList &L,int i,int &e){
	LinkList p=L;
    int j=0;
    while(p->next&&j<i-1){
    	p=p->next;
    	++j;
    }
    if(!p->next||j>i-1) return false;
    //-------------------------------------------------------
	//下面的顺序不能随意修改，一定理清转换关系 
	LinkList q=p->next;
    p->next=q->next;
	e=q->data;
	free(q);  //注意回收 
	//------------------------------------------------------------- 
 	return true;
}

int main(){
	return 0;
} 
