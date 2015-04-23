////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-04-23 19:56:02
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1730
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:340KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdlib>
using namespace std;
int SG(int a,int b)
{
	//����Ľ�ģ���̾��ǣ������������ӿ϶�ʱ�໥�ӽ�������
	//���Ӽ�ľ���-1���Ա�ʾΪnimÿ���еĻ������������Ϊʲô-1��
	return abs(a-b) - 1;
}
int main()
{
	int n,m,t,j,ans;
	while(cin >> n >> m)
	{
		ans = 0;
		for(int i = 1; i <= n; i++)
		{
			cin >> t >> j;
			ans ^= SG(t,j);
		}
		if(ans == 0)
		{
			cout << "BAD LUCK!" << endl;
		}
		else
		{
			cout << "I WIN!" << endl;
		}
	}
	return 0;
}
