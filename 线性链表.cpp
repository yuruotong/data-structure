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
    //�������ص� 
    LinkList s=(LinkList)malloc(sizeof(LNode)); //����µĽڵ�S 
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
	//�����˳���������޸ģ�һ������ת����ϵ 
	LinkList q=p->next;
    p->next=q->next;
	e=q->data;
	free(q);  //ע����� 
	//------------------------------------------------------------- 
 	return true;
}

int main(){
	return 0;
} 
