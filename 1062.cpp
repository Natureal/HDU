////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-11 23:52:15
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1062
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int main()
{
	int n,i,j;
	char c[1001],ch[1001];
	scanf("%d",&n);
	getchar();

	while(n--)
	{
		gets(c);
		i=0;
		while(c[i])
		{
			j=0;
			while(c[i]!=' ' && c[i]!='\0')//��Ҫ˼���ǰ��ַ����еĵ��ʿٳ�������洢�������������
			{
				ch[j]=c[i];
				i++;
				j++;
			}
			ch[j]='\0';
			strrev(ch);//�˺����ﱤ��
			printf("%s",ch);
			if(c[i] == ' ')
	      	{
					printf(" ");
					i++;
			}
		}
		printf("\n");
	}
	return 0;
}