#include <stdio.h>
#include <string>
#include <malloc.h>
#include <iostream>
using namespace std;
typedef struct LNode {
	int mima;
	struct LNode *next;

}LNode, *LinkList;

LinkList pTail = NULL;
bool CreateList(LinkList &L) {

	L = new LNode();

	if (!L) {
		cout << "L����ʧ��" << endl;

		return false;
	}


	L->next = NULL;//ͷ��� 
	return true;

}
bool ListDelete(LinkList L, int &m,int &number) {
	LinkList p = L;
	int j=0;
	while (p->next && j<m-2) {
		j++;
		p = p->next;
	}
	if (!p->next) {
		cout << "ɾ��ʧ��" << endl;
		return false;
	}
	LinkList q = p->next;
	p->next = q->next;
	m=q->mima;
	number--;
	free(q);
	
	return true;
}
bool ListInsert(LinkList L, int i_mima) {
	if(L->next==NULL) {
	L->mima=i_mima;
	L->next=L;
	
	return true;
}
	else{
		LinkList s = new LNode();
	if (!s) cout << "�����½ڵ��ڴ�ʧ��" << endl;
	s->mima=i_mima;
	LinkList p=L;
	while(p->next!=L){
		p=p->next;
	}
	s->next =L ;
	p->next = s;
	
	return true;
	}
	
}
void show(LinkList L){
	int i=1;
	while(i!=11){
	  cout<<"��"<<i<<"����"<<endl;
	  cout<<"����:"<<L->mima<<endl;
    	i++;
      L=L->next;
	}
	cout<<"------------------------------------------------------"<<endl;

}
int main(){
	LinkList L;
	CreateList(L);
	pTail=L;
	int mima[100];  //���ڱ������� 
	int m;
	int mima_number;
	cout<<"�������������"<<endl;
	cin>>mima[0];  //��������� 
	mima_number=mima[0];
	cout<<"����������"<<endl;
	for(int i=1;i<=mima[0];i++){   //ע�����mima[0]���ڱ������������mima[1]�Ժ�������� 
		cin>>mima[i];
		ListInsert(L,mima[i]);  //�������� 
	}
	show(L);
	cout<<"������m"<<endl;
	cin>>m;
	
	for(int i=0;i<mima[0];i++){
	cout<<m%mima_number<<endl;
    int m0=m;
	ListDelete(L,m,mima_number);
	 show(L);
	  for(int k=0;k<m0;k++){
	
    	L=L->next;
	}
	
}
	
}

