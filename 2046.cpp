////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-17 11:56:53
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2046
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
//�ӵ�һ������ʼ�����ƿ��Ժ�ţ�����������ٷ�һ�ţ�ռ����Ҳ�������ŷ�ռһ����������
//��ת���ɣ�N�׵�·��һ�ο�����1m��2m���м����߷��������ˣ���������쳲�����������⣡
#include <stdio.h>
int main()
{
	int n,i;
	long long a[51]={0,1,2,3};
	while(scanf("%d",&n)!=EOF)
	{
		for(i=4;i<=n;i++)
		{
			a[i]=a[i-1]+a[i-2];
		}
		printf("%I64d\n",a[n]);
	}
	return 0;
}