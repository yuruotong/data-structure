//A          B                c
//1,��A��n-1�����ӽ���c�ƶ���B
//2,��A�ĵ�n�������ƶ���C
//3,��B�ϵ�n-1�����ӽ���A�ƶ���C
// 
#include<stdio.h>
void hannuota(int n,char A,char B,char C){   
 //�����һ�����ӣ�ֱ�Ӵ�x�ƶ���z 
 //����x�ϵ�n-1�����ӽ���z�Ƶ�y
//��x�ϵĵ�n�������ƶ���z
//��y�ϵ�n-1�����ӽ���x�ƶ���z
if(n==1){//�����һ�����ӣ�ֱ�Ӵ�x�ƶ���z 
	printf("�����Ϊ%d�����Ӵ�%d�ƶ���%d",n,A,C);
} 
else{
	hannuota(n-1,A,C,B);//����x�ϵ�n-1�����ӽ���z�Ƶ�y
	printf("�����Ϊ%d�����Ӵ�%d�ƶ���%d",n,A,C);//��x�ϵĵ�n�������ƶ���z
	hannuota(n-1,B,A,C);//��y�ϵ�n-1�����ӽ���x�ƶ���z
	
}
	
}
int main(){
	char ch1='A';
	char ch2='B';
	char ch3='c'; 
	int n;
	printf("���������ӵĸ���");
	scanf("%d",n);
	hannuota(n,ch1,ch2,ch3);
	return 0;
} 
