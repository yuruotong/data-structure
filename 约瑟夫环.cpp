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
	cout<<"L����ʧ��"<<endl;
	return false;
}

	L->next=NULL;//ͷ��� 
	return true; 
	
}
bool ListDelete(LinkList &L,int in_put){  //in_put����ָ��ɾ���ĸ���� 
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
	 pTail->next=NULL;//β�ڵ� 
 	 if(!pTail) cout<<"����ʧ��"<<endl;
	 LinkList s=(LinkList)malloc(sizeof(LNode));
	 if(!s) cout<<"�����ڴ�ʧ��"<<endl;
	 s->data=i_data;
	 pTail->next=s; 
	 s->next=L;
	 pTail=s;
	 return true;
 }
 //������������� 
 int show(LinkList L,int in_put){  //in_put���ڲ�ѯ����ǵڼ����ڵ� 
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
	cout<<"�������������"<<endl;
	cin>>mima[0];  //��������� 
	cout<<"����������"<<endl;
	for(int i=1;i<=mima[0];i++){
		cin>>mima[i];
		ListInsert(L,mima[i]);
	}
	cout<<"������m"<<endl;
	cin>>m;
	while(mima[0]){
	m=show(L,[m%mima[0]);
	cout<<shouw(m);
	ListDelete(L,m);
	
}
	
}

