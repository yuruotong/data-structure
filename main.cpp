#include"stdio.h"
#include"malloc.h"
#include"string.h"
#include"stdlib.h"
typedef struct{
	char *ch;
	int length;
}HString;
void InsertString(HString*T,char in_put[]){
	if(!(T->ch=(char*)malloc(100*sizeof(char))))printf("error");
	for(int i=1;i<=strlen(in_put);i++){
		T->ch[i]=in_put[i];
		T->length=i;
	
	}

}
void getnext(HString *T,int next[]){
int i=1;
next[1]=0;
int j=0;
while(i<T->ch[0]){
	if(j==0||T->ch[i]==T->ch[j]){
		++i;
		++j;
		if(T->ch[i]!=T->ch[j]) next[i]=j;
		else next[i]=next[j];
	
	}
	else j=next[j];
}
} 
int pipei(HString *S,HString *T,int &pos,int next[]){
	int i = pos;
	int j=1;
	while(i<=S->ch[0]&&j<=T->ch[0]){
		if(j==0||S->ch[i]==T->ch[j]){i++;j++;}
		else j=next[j];
	}
	if(j>T->ch[0])return i-T->ch[0];
	else return 0;

}
int main(){
int pos;
int next2[100];
HString *T1=(HString*)malloc(sizeof(HString));
HString *T2=(HString*)malloc(sizeof(HString));
InsertString(T1,"adfadsfadf");
InsertString(T2,"adfad");
getnext(T2,next2);
pipei(T1,T2,pos,next2);
 //---------------------------

//---------------------------
printf("%d",pos);
system("pause");




return 0;
}