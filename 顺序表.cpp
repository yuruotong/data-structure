#include<malloc.h>
#include<stdio.h>
#define LIST_SIZE 2
#define LISTCREATER 10

typedef struct{
	int *elem;//定义数据类型 
	int length;//含有的元素长度 
	int listsize;//表的总长度 
}SqList;
bool InitList_Sq(SqList&L){
	L.elem=(int*)malloc(LIST_SIZE*sizeof(int));//int可以随时修改 
	if(! L.elem) printf("存储分配失败");
	L.length=0;
	L.listsize=LIST_SIZE; 
	return true;
}
bool ListInsert_Sq(SqList &L,int i,int e){//e的类型可以随时修改 
	if(i<1||i>L.length+1) return false; //注意这里的长度 
	//---------------------------------------------------------------------------
	//注意以下是重点，用于拓展顺序表内存 
	if(L.length>=L.listsize){
	int *newbase=(int*)realloc(L.elem,(L.listsize+LISTCREATER)*sizeof(int));
	if(!newbase) printf("分配失败"); //注意realloc的返回值 
 	L.elem=newbase;
	L.listsize +=LISTCREATER; 
	} 
	//---------------------------------------------------------------------------------
	int *q=&(L.elem[i-1]); //q的类型可以随时修改 
	for(int *p=&(L.elem[L.length-1]);p>=q;--p) *(p+1)=*p;
	*q=e;
	++L.length;
	return true;
}
bool ListDelete_Sq(SqList &L,int i,int &e){
	if((i<1)||(i>L.length)) return false;
	int *p=&(L.elem[i-1]);  //取出元素给e 
	e=*p;
	int *q=L.elem+L.length-1; //取出尾元素 
	for(++p;p<=q;++p) *(p-1)=*p;//所有元素前移 
	--L.length;
	return true;
	
} 
int main(){
SqList list1;
InitList_Sq(list1);
ListInsert_Sq(list1,1,9);
ListInsert_Sq(list1,2,8);
ListInsert_Sq(list1,3,7);
ListInsert_Sq(list1,4,6);
ListInsert_Sq(list1,5,5);
ListInsert_Sq(list1,6,4);
ListInsert_Sq(list1,7,3);
printf("第七个位置的数值是:%d",list1.elem[5]);


return 0; 
} 

