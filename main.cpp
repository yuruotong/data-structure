#include<stdio.h>
#include"string.h"
#include<malloc.h>
#include"stdlib.h"
struct pTree{
char data;
pTree *pLChild;
pTree *pRChild;

};
void creat(struct pTree*&TT){
	char in_put;
	scanf_s("%c",&in_put,2);

	if (in_put == '#') TT = NULL;
		else{
		if(!(TT=(struct pTree*)malloc(sizeof(pTree)))) printf("����ʧ��");
		TT->data=in_put;
		creat(TT->pLChild);
		creat(TT->pRChild);
		
	
	}

	
	}
   



void xianxu(struct pTree* T){
	if(NULL!=T){
	printf("%c",T->data);
	if(NULL!=T->pLChild)
	xianxu(T->pLChild);
	if(NULL!=T->pRChild)
	xianxu(T->pRChild);
	}

}
void zhongxu(struct pTree* T){
	if(NULL!=T){
	
	if(NULL!=T->pLChild)
	zhongxu(T->pLChild);
	printf("%c",T->data);
	if(NULL!=T->pRChild)
	zhongxu(T->pRChild);
	}

}
void houxu(struct pTree* T){
	if(NULL!=T){
	if(NULL!=T->pLChild)
	houxu(T->pLChild);
	
	if(NULL!=T->pRChild)
	houxu(T->pRChild);
	printf("%c",T->data);
	}

}

void print(struct pTree* T, int t) {

	
	if (NULL!=T) {

		print(T->pRChild, t + 5);
		int i;
		for (i = 0; i < t; i++) printf(" ");
		printf("%c\n", T->data);
		print(T->pLChild, t + 5);
	}

}

int main(){
printf("��������������\n");

struct pTree* TT=(struct pTree*)malloc(sizeof(pTree)); //���ڱ�����һ�����ĵ�ַ

creat(TT);
//printf("����");
//xianxu(TT);
//printf("����");
//zhongxu(TT);
//printf("����");
//houxu(TT);

print(TT,5);
system("pause");

return 0;}