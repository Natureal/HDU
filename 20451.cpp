////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-17 11:24:13
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2045
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:240KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,i;
	double a[51];
	a[1]=3;
	a[2]=6;
	a[3]=6;
	/*
a[i]=�����֣�
1): ǰi-1��β��ͬ �����պ�a[i-1]
2): ǰi-1��β��ͬ ��Ȼ��һ�����i-2����ɫ�Ͳ�����ͬ�ˣ������պ�a[i-2]
���Ǵ�ʱ���һ������ȡ������ɫ����������xxxxxxxxxxx2
������ע�⵱n=3ʱ�����湫ʽ�ǲ����ϵģ���
*/

	while(scanf("%d",&n)!=EOF)
	{
		for(i=4;i<=n;i++)  //�������ֱ��for(i=4;i<51;i++)������е�a[],Ȼ�����������ȡ�����������ϴ��ģ����Ӧ��
		{
			a[i]=2*a[i-2]+a[i-1];
		}
		printf("%.lf\n",a[n]);
	}
	return 0;
}