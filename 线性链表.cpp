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
 	
 }

int main(){
	return 0;
} 
