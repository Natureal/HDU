////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-03 22:34:05
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1427
////Problem Title: 
////Run result: Accept
////Run time:296MS
////Run memory:344KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1427.cpp
    > Author: cpu
    > email: 564374850@qq.com
    > Created Time: 2014��03��03�� ����һ 21ʱ17��34��
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
int val[4],flag;
void dfs(int a,int count,int b)
{
	if(flag)
		return;
	if(count==3)//������������ﵽ����˵��ǰ�������Ѿ����㣬������е��ĸ���������
	{
		if(a+b==24)//��
			flag=1;
		else if(a-b==24)//��
			flag=1;
		else if(a*b==24)//��
			flag=1;
		else if(b!=0&&a%b==0&&a/b==24)//����Ҫ�Լ��жϣ�����Ҫ֤����24������в�����*����*��������
			flag=1;                   //��˵õ����������ҽ���(a/b)*(c/d)==24�����㷨���ܵõ�����ô
		return;                       //a,b,c,d���ʣ���Ϊ�����ʶ�����ͨ��dfs���̴ﵽ�ϴ���������С���ﵽЧ����
	}                                 //��ôa*c==24*b*d����a,b,c,d���������ʣ�ì�ܣ�
	count++;
	dfs(a+b,count,val[count]);//a��b�������㣬������dfs����������ֵ����
	dfs(a-b,count,val[count]);
	dfs(a*b,count,val[count]);
	if(b!=0&&a%b==0)
		dfs(a/b,count,val[count]);
	dfs(a,count,b+val[count]);//��b����һ������������
	dfs(a,count,b-val[count]);
	dfs(a,count,b*val[count]);
	if(val[count]!=0&&b%val[count]==0)
		dfs(a,count,b/val[count]);
	return;
}
int main()
{
	char temp[4][2];
	while(cin>>temp[0]>>temp[1]>>temp[2]>>temp[3])
	{
		//cout<<temp[0]<<endl<<temp[1]<<endl<<temp[2]<<endl<<temp[3]<<endl;
		for(int i=0;i<4;i++)
		{
			if(temp[i][0]=='A')val[i]=1;
			else if(temp[i][0]=='J')val[i]=11;
			else if(temp[i][0]=='Q')val[i]=12;
			else if(temp[i][0]=='K')val[i]=13;
			else if(temp[i][0]=='1'&&temp[i][1]=='0')val[i]=10;
			else val[i]=temp[i][0]-'0';
			//printf("%d\n",val[i]);
		}
		sort(val,val+4);
		flag=0;
	//	do
	//	{
	//		dfs(val[0],1,val[1]);
	//	}while(!flag&&next_permutation(val,val+4));
		while(!flag)
		{
			dfs(val[0],1,val[1]);
			if(!flag&&next_permutation(val,val+4));
			else break;
		}
		if(flag)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
