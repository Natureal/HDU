////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-10 14:51:54
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1247
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:5940KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1247.c
    > Author: cpu
    > email: 564374850@qq.com
    > Created Time: 2014年03月09日 星期日 22时29分41秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#define MAX 26
char s[60000][MAX];
struct Trie
{
	struct Trie *next[MAX];
	int cnt;
};
struct Trie *root; 

void Insert(char *str)
{
    int len=strlen(str);
    struct Trie *p=root,*q;
    for(int i=0;i<len;i++)
    {
        int id=str[i]-'a';
        if(p->next[id]==NULL)
        {
            q=(struct Trie *)malloc(sizeof(struct Trie));
            for(int j=0;j<MAX;j++)
            {
                q->next[j]=NULL;
            }
	    q->cnt=0;
            p->next[id]=q;
        }
	p=p->next[id];
    }
    p->cnt=1;
    return;
}
  
int findTrie(char *str)
{
    int len=strlen(str);
    Trie *p=root;
    for(int i=0;i<len;i++)
    {
        int id=str[i]-'a';
        if(p->next[id]!=NULL)
        {
            p=p->next[id];
        }
        else
            return 0;
    }
    return p->cnt;
}
int dealTrie(struct Trie *T)
{
	int i;
	if(T==NULL)
		return 0;
	for(int i=0;i<MAX;i++)
	{
		if(T->next[i]!=NULL)
			dealTrie(T->next[i]);
	}
	free(T);
	return 0;
}
int main()
{  
	int i,j,k,len,num=0;
	char s2[MAX];
	root=(struct Trie *)malloc(sizeof(struct Trie));
	for(int i=0;i<MAX;i++)
	{
		root->next[i]=NULL;
	}
	while(scanf("%s",s[num])!=EOF)
	{
		Insert(s[num++]);
	}
	for(i=0;i<num;i++)
	{
		len=strlen(s[i]);
		for(j=0;j<len-1;j++)	
		{
			for(k=0;k<=j;k++)
			{
				s2[k]=s[i][k];
     		}
    		s2[k]='\0';
     		if(findTrie(s2))
			{
				strcpy(s2,s[i]+k);
				if(findTrie(s2))
				{
					puts(s[i]);
					break;
				}
			}
		}
	}
	//dealTrie(root);
	return 0;
}