#include "stdio.h"
#include"malloc.h"
#include "stdlib.h"

typedef struct{
	char *ch;
	int length;

}HString;
void InCreat(HString &L,char in_put[]){
	int i = 0;

	while (in_put[i]!='\0') i++;  //���������ȷ��in_put��Ԫ�صĸ���
	if(!(L.ch = (char*)malloc(i*sizeof(char)+1))) printf("����ʧ��");
	for (int k = 0; k <= i - 1; k++){
		L.ch[k] = in_put[k];
		}
	L.ch[i] = 0;
	L.length = i;
}
void get_next(HString L, int next[]){
	int i = 1;
	next[1] = 0;
	int j = 0;
	while (i < L.length){
		if (j == 0 || L.ch[i-1] == L.ch[j-1]){
			++i;
			++j;
			next[i] = j;

		}

		else j = next[j];

	}
}
void KMP(HString A,HString B,int next[],int pos){
	int i = pos;
	int j = 1;
	while (i <= A.length&&j <= B.length){
		if (j == 0 || A.ch[i-1] == B.ch[j-1]){
            i++;
			j++;}
		else j = next[j];
	}
	if (j>B.length)printf("ƥ��ɹ�,�ڵ�%d�ҵ�",i-2);
	else printf("ƥ��ʧ��");

}




int main(){
	HString a;
	HString b;
	char a1[100];
	char b1[100];
	int next[100];
	int pos=1;//�ڼ���λ��
	printf("���������ַ�+ƥ���ַ�:\n");
	scanf_s("%s", a1, 100);
	scanf_s("%s", b1, 100);
	InCreat(a, a1);
	InCreat(b, b1);
	get_next(b, next);
	KMP(a, b, next, pos);
	system("pause");

}