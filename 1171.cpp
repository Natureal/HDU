////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-26 23:18:00
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1171
////Problem Title: 
////Run result: Accept
////Run time:2281MS
////Run memory:2184KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<string.h>
#define max 250001          //��Χ����Ŀ�ܶ��Ķ��ڴ����������飬�����������
int c1[max],c2[max];
int main()
{
    int n,v[55],m[55];
    int j,k,i,sum,div;
    while(scanf("%d",&n)!=EOF && n>=0)
    {
        sum=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&v[i],&m[i]);
            sum+=m[i]*v[i];
        }
        div=sum/2;
        memset(c1,0,sizeof(c1)+1);
        memset(c2,0,sizeof(c2)+1);
        for(i=0;i<=m[1];i++)
            c1[v[1]*i]=1;
        for(i=2;i<=n;i++)//ĸ����ѭ���������ְ취��һ��ѭ����㣬һ��ѭ���ڲ�
        {
            for(j=0;j<=sum;j++)             
            {
                for(k=0;k+j<=sum && k<=v[i]*m[i];k+=v[i])
                    c2[j+k]+=c1[j];
            }
            for(j=0;j<=sum;j++)
            {
                c1[j]=c2[j];
                c2[j]=0;
            }
        }
		for(i=div;i>=0;i--)//���ĳ��������������䡿
		{
			if(c1[i]!=0)    break;
		}
		printf("%d %d\n",sum-i,i);
    }//ע��߽����Ŀ��ƣ�1,0֮���
    return 0;
}