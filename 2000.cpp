////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-15 15:51:57
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2000
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	char a,b,c,x,y,z;
	while(scanf("%c%c%c",&a,&b,&c)!=EOF) //���ո�ʵ�飬��Ҳ���Զ����µ��ַ������뵫���ã�
	{
		getchar();//�Ե��س������������ַ�ʱ��Ҫע��س������⣩
		x=a>b?a:b;
		x=x>c?x:c;
		z=a<b?a:b;
		z=z<c?z:c;
		y=a+b+c-x-z;
		printf("%c %c %c\n",z,y,x);
	}
	return 0;
}