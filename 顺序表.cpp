#include<malloc.h>
#include<stdio.h>
#define LIST_SIZE 100
#define LISTCREATER 10

typedef struct{
	int *elem;//������������ 
	int length;//���е�Ԫ�س��� 
	int listsize;//����ܳ��� 
}SqList;
bool InitList_Sq(SqList&L){
	L.elem=(int*)malloc(LIST_SIZE*sizeof(int));//int������ʱ�޸� 
	if(! L.elem) printf("�洢����ʧ��");
	L.length=0;
	L.listsize=LIST_SIZE; 
	return true;
}
bool ListInsert_Sq(SqList &L,int i,int e){//e�����Ϳ�����ʱ�޸� 
	if(i<1||i>L.length+1) return false; //ע������ĳ��� 
	//---------------------------------------------------------------------------
	//ע���������ص㣬������չ˳����ڴ� 
	if(L.length>=L.listsize){
	int *newbase=(int*)realloc(L.elem,(L.listsize+LISTCREATER)*sizeof(int));
	if(!newbase) printf("����ʧ��"); //ע��realloc�ķ���ֵ 
	L.elem=newbase;
	L.listsize +=LISTCREATER; 
	} 
	//---------------------------------------------------------------------------------
	int *q=&(L.elem[i-1]); //q�����Ϳ�����ʱ�޸� 
	for(int *p=&(L.elem[L.length-1]);p>=q;--p) *(p+1)=*p;
	*q=e;
	++L.length;
	return true;
}

