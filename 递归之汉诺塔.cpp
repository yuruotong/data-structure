//A          B                c
//1,把A的n-1个盘子借助c移动到B
//2,把A的第n个盘子移动到C
//3,把B上的n-1个盘子借助A移动到C
// 
#include<stdio.h>
void hannuota(int n,char A,char B,char C){   
 //如果是一个盘子，直接从x移动到z 
 //否则将x上的n-1个盘子借助z移到y
//将x上的第n个盘子移动到z
//将y上的n-1个盘子借助x移动到z
if(n==1){//如果是一个盘子，直接从x移动到z 
	printf("将编号为%d个盘子从%d移动到%d",n,A,C);
} 
else{
	hannuota(n-1,A,C,B);//否则将x上的n-1个盘子借助z移到y
	printf("将编号为%d个盘子从%d移动到%d",n,A,C);//将x上的第n个盘子移动到z
	hannuota(n-1,B,A,C);//将y上的n-1个盘子借助x移动到z
	
}
	
}
int main(){
	char ch1='A';
	char ch2='B';
	char ch3='c'; 
	int n;
	printf("请输入盘子的个数");
	scanf("%d",n);
	hannuota(n,ch1,ch2,ch3);
	return 0;
} 
