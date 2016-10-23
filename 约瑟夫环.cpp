#include <stdio.h>
#include <string>
#include <malloc.h>
#include <iostream>

using namespace std; 
 typedef struct LNode{
 	int data;

 	struct LNode *next;
 }LNode,*LinkList;
bool CreateList(LinkList &L){  
    
	L=(LinkList)malloc(sizeof(LNode));

	if(!L) {
	cout<<"L分配失败"<<endl;
	return false;
}

	L->next=NULL;//头结点 
	return true; 
	
}
bool ListDelete(LinkList &L,int in_put){  //in_put用于指定删除哪个结点 
	LinkList p=L;
	while(p->next&&p->data!=in_put){
		p=p->next;
		}
	if(!p->next) return false; 
	LinkList q=p->next;
	p->next=q->next;
	free(q);
	return true;
} 
 bool ListInsert(LinkList &L,int i_data){
 	
 	 static LinkList pTail=L;
	 pTail->next=NULL;//尾节点 
 	 if(!pTail) cout<<"插入失败"<<endl;
	 LinkList s=(LinkList)malloc(sizeof(LNode));
	 if(!s) cout<<"分配内存失败"<<endl;
	 s->data=i_data;
	 pTail->next=s; 
	 s->next=L;
	 pTail=s;
	 return true;
 }
 //这个函数有问题 
 int show(LinkList L,int in_put){  //in_put用于查询这个是第几个节点 
 	LinkList p=L->next; 
 	int j=0;
 	while(p&&(j<in_put-1))p=p->next;
 	return j;
 	
 	
}
int result(){
	
}
int main(){
	LinkList L;
	CreateList(L);
	int mima[100];
	int m;
	cout<<"请输入密码个数"<<endl;
	cin>>mima[0];  //存密码个数 
	cout<<"请输入密码"<<endl;
	for(int i=1;i<=mima[0];i++){
		cin>>mima[i];
		ListInsert(L,mima[i]);
	}
	cout<<"请输入m"<<endl;
	cin>>m;
	while(mima[0]){
	m=show(L,[m%mima[0]);
	cout<<shouw(m);
	ListDelete(L,m);
	
}
	
}

