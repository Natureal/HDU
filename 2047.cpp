////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-17 13:32:49
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2047
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
//��nλ�ַ��������һλ��O���ַ����ĸ���Ϊa[n],���һλ����O���ַ����ĸ�����b[n],
//���ַ�������Ϊx[n]��
//����
//x[n]=a[n]+b[n];
//a[n]=b[n-1];
//b[n]=2*x[n-1];
//====>x[n]=2*x[n-1]+2*x[n-2]
#include <stdio.h>
int main()
{
	int n,i;
	_int64 a[41];
	a[1]=3,a[2]=8;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=3;i<=n;i++)
		{
			a[i]=2*(a[i-1]+a[i-2]);
		}
		printf("%I64d\n",a[n]);
	}
	return 0;
}