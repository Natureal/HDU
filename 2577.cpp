////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-04-08 22:01:57
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2577
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int a[105],b[105],t;
	char s[105];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s + 1);
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		int len = strlen(s + 1);
		for(int i = 1 ;i <= len;i ++)//˼·����a��¼��ɴ˴�type��ʹcaps lock�Ƶ�״̬Ϊ��
		{
			if(s[i] >= 'a' && s[i] <= 'z')//Сд
			{
				a[i] = min(a[i-1] + 1,b[i-1] + 2);//bҪ��lock��
				b[i] = min(a[i-1] + 2,b[i-1] + 2);//bҪ��shift
			}
			else //��д��ĸ
			{
				a[i] = min(a[i-1] + 2,b[i-1] + 2);//aҪ��shift����bҪ�����ȡ��lock��
				b[i] = min(a[i-1] + 2,b[i-1] + 1);//aҪ��lock����bֱ�Ӵ�
				if(i == 1)
				{
					b[i] ++;
				}
			}
		}
		b[len]++;
		printf("%d\n",a[len]<b[len]?a[len]:b[len]);
	}
	return 0;
}