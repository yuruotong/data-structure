#include <stdio.h>
#include <string>
#include <malloc.h>
#include <iostream>
using namespace std; 
 typedef struct LNode{
 	string name;
 	string address;
 	struct LNode *next;
 }LNode,*LinkList;
bool CreateList(LinkList &L){  
	L=(LinkList)malloc(sizeof(LNode));
	if(!L)return false;
	L->next=NULL;//ͷ��� 
	return true; 
	
}
bool ListDelete(LinkList &L,string in_put){
	LinkList p=L;
	int j=0; 
	while(p->next&&(p->name!=in_put||p->name!=in_put)){
		p=p->next;
	
		
	}
	if(!p->next) return false; 
	LinkList q=p->next;
	p->next=q->next;
	free(q);
	return true;
} 
 bool ListInsert(LinkList &L,string i_name,string i_address,int i){
 	LinkList p=L;
 	int j=0;
 	while(p&&j<i-1){
 		p=p->next;
 		j++;
	 }
	 if(!p||j>i-1) return false;
	 LinkList s=(LinkList)malloc(sizeof(LNode));
	 s->name=i_name;
	 s->address=i_address;
	 s->next=p->next;
	 p->next=s;
	 return true;
 }
 void show(LinkList L,string in_put){
 	LinkList p=L; 
 	while(p&&(p->name!=in_put||p->address!=in_put))p=p->next;
 	cout<<p->name<<endl;
 	cout<<p->address<<endl;
 	
}

  


int main() {
	LinkList City;
	CreateList(City);
	int choose=0;//�����û��Ĳ���ѡ�� 
	int location=0;//����ѡ�����λ�� 
	 
    string name,address;
//---------------------------------------------------�˴�Ӧ���и�ѭ�� 
while(1){

	cout<<"���ã�1:���룬2:ɾ����3:��ѯ��4:�˳�"<<endl; 
	cin>>choose; 
	if(choose==4) break;
	else{
	
	switch(choose){
		case 1:
		cout<<"�����룺��������+��ַ+����λ��:"<<endl;
        cin>>name;
		cin>>address;
		cin>>location;
        ListInsert(City,name,address,location);
        break;
       
	    case 2:
        cout<<"������ɾ������:����/��ַ"<<endl;
        cin>>name;
        ListDelete(City,name);
        break;
        	
        case 3:
        cout<<"������Ҫ��ѯ������:"<<endl;
        cin>>name;
        show(City,name);
        break;
        	
        	
	} 
}
}
	
	return 0;
}

