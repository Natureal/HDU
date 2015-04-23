////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-03 22:23:30
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1427
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:328KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: sy.cpp
    > Author: cpu
    > email: 564374850@qq.com
    > Created Time: 2014��03��03�� ����һ 22ʱ12��24��
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
int res[4];
void dfs(int sum, int cur, int temp);
bool flag = 0;
int main()
{

	char s[3];
	int i,j,k;
	while(1)
	{

		for(i = 0;i < 4;i ++)
		{

			if(scanf("%s",s) == EOF) return 0;
			if(s[0] == 'A') res[i] = 1;
			else if(s[0] == 'J') res[i] = 11;
			else if(s[0] == 'Q') res[i] = 12;
			else if(s[0] == 'K') res[i] = 13;
			else if(s[0] == '1' && s[1] == '0') res[i] = 10;
			else res[i] = s[0] - '0';
		}
		sort(res, res+4);
		flag = 0;
		do
		{

			dfs(res[0], 1, res[1]);
		}while(next_permutation(res, res+4)&&!flag);
		if(flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
void dfs(int sum, int cur, int temp)
{

	if(flag)
		return;
	if(cur==3)
	{

		if(sum+temp==24)
			flag=1;
		if(sum-temp==24)
			flag=1;
		if(sum*temp==24)
			flag=1;
		if(temp!=0&&sum%temp==0&&sum/temp==24)
			flag=1;
		return;
	}
	dfs(sum+temp, cur+1, res[cur+1]);
	dfs(sum-temp, cur+1, res[cur+1]);
	dfs(sum*temp, cur+1, res[cur+1]);
	if(temp!=0&&sum%temp==0)
		dfs(sum/temp, cur+1, res[cur+1]);
	dfs(sum, cur+1, temp+res[cur+1]);
	dfs(sum, cur+1, temp-res[cur+1]);
	dfs(sum, cur+1, temp*res[cur+1]);
	if(res[cur+1]!=0&&temp%res[cur+1]==0)
		dfs(sum, cur+1, temp/res[cur+1]);
}