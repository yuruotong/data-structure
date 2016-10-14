#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#include"malloc.h"
typedef struct{
	int *base;
	int *top;
	int stacksize;
}SqStack;
bool InitStack(SqStack &s){
	s.base=(int*)malloc(STACK_INIT_SIZE*sizeof(int));
	if(!s.base) return false;
	s.top=s.base;
	s.stacksize=STACK_INIT_SIZE;
	return true; 
}
bool GetTop(SqStack s,int &e){
	if(s.top==s.base) return false;
	e=*(s.top-1);
	return true;
}
bool push(SqStack &s,int e){
	if(s.top-s.base>=s.stacksize) {
		s.base=(int*)realloc(s.base,(s.stacksize+STACKINCREMENT)*sizeof(int));
		if(!s.base)false;
		s.top=s.base+s.stacksize;
		s.stacksize+=STACKINCREMENT;
	}
	*s.top++=e;
	return true;
	}
bool pop(SqStack &s,int &e){
	if(s.top=s.base) return false;
	e=*--s.top;
	return true;
}
int main(){
	return 0;
}
