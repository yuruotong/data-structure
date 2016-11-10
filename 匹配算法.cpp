#include "stdio.h"
#include "malloc.h"
#include"stdlib.h"
typedef struct{

	char *ch;
	int length;
}HString;
void InCreat(HString &L, char*in_put){
	int i = 0;
	while (in_put[i]) i++;
	L.ch = (char*)malloc(i*sizeof(char) + 1);
	for (int k = 0; k < i; k++){
		L.ch[k] = in_put[k];
}
	L.ch[i] = 0;
	L.length = i;

}
void pipei(HString A, HString B){
	int i = 0;
	int j = 0;
	while (i <= A.length-1&&j <= B.length-1){
		if (A.ch[i] == B.ch[j]){ 
			i++;
		    j++;
		}
		else {
		i = i - j + 1;
		j = 0;
		}



	}
	if (j >= B.length)printf("匹配成功，在第%d个位置找到", i-B.length+1);
	else printf("匹配失败");
}
int main(){
	HString a;
	HString b;
	char a1[100];
	char b1[100];
	printf("请输入主字符+匹配字符\n");
	scanf_s("%s", a1, 100);
	scanf_s("%s", b1, 100);
	InCreat(a, a1);
	InCreat(b, "b");
	pipei(a, b);
	system("pause");
}