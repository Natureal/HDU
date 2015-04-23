////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-05 23:35:12
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1241
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:428KB
//////////////////System Comment End//////////////////
#include <iostream>   
#include <stdio.h>   
using namespace std;   
  
char map[101][101];   
int n, m, sum;   
  
void dfs(int i, int j)   
{   
    //���õ㲻���л�Խ�磬����   
    if(map[i][j]!='@' || i<0 || j<0 || i>=m || j>=n) return;       
    else    //���򣬱�Ǹõ�Ϊ�����У�����8����������   
    {   
        map[i][j] = '!';   
        dfs(i-1, j-1);   
        dfs(i-1, j);   
        dfs(i-1, j+1);   
        dfs(i, j-1);   
        dfs(i, j+1);   
        dfs(i+1, j-1);   
        dfs(i+1, j);   
        dfs(i+1, j+1);   
    }   
}   
  
int main()   
{   
    int i, j;   
    while(cin>>m>>n)   
    {   
        if(m==0 || n==0) break;   
        sum = 0;   
        for(i = 0; i < m; i++)   
          for(j = 0; j < n; j++)   
               cin>>map[i][j];   
        for(i = 0; i < m; i++)   
        {   
            for(j = 0; j < n; j++)   
            {   
               if(map[i][j] == '@')   
               {   
                    dfs(i, j);   
                    sum++;   
                }   
            }   
        }   
        cout<<sum<<endl;   
  }   
      return 0;   
}

