////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-09 19:31:27
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2022
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:240KB
//////////////////System Comment End//////////////////
#include <stdio.h>

#define N 100

int main()
{
	int m,n,a[N][N],i,j,max,ms,ns;
	while(scanf("%d %d",&m,&n)!=EOF)
	{
		max = ms = ns = 0;
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%d",&a[i][j]);
				if(a[i][j]<0)

				{	ms = max >= (-a[i][j]) ?  ms : i;
					ns = max >= (-a[i][j]) ?  ns : j;
					max = max >= (-a[i][j]) ? max : (-a[i][j]);//��max����Ƚ�ʱ���Ѹ�ֵת��Ϊ��ֵ���бȽϣ���������ж�a[ms][ns]�Ƿ�Ϊ����
				}
				else
				{
					ms = max >= a[i][j] ? ms : i;
					ns = max >= a[i][j] ? ns : j;
					max = max >= a[i][j] ? max : a[i][j];
				}
			}
		}
		if( a[ms][ns] < 0)
		{
			max = -max;
		}
		printf("%d %d %d\n",ms+1,ns+1,max);
	}
	return 0;
}