////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-05 22:18:11
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1010
////Problem Title: 
////Run result: Accept
////Run time:515MS
////Run memory:256KB
//////////////////System Comment End//////////////////
#include<iostream>    
using namespace std;    
int sx,sy,ex,ey;  //�����յ�����  
int n,m;  //�Թ�����������  
char map[10][10];// �Թ�  
int flag;//�жϳɹ�  
int d[4][2]={0,1,1,0,0,-1,-1,0};  // �¡��ҡ��ϡ���  
void dfs(int x,int y,int t)    
{     
    /** 1���ų�����֦ */  
    if(flag==1) return ;// �ɹ��򷵻�  
    // ʣ��ʱ�䲻�����ߵ��յ� ���� ��ǰ�����յ���������ĺ� �� ʣ��ʱ��֮����ż�Բ�ͬ����ֱ�ӷ������  
    if(t<abs(ex-x)+abs(ey-y)||(t-abs(ex-x)+abs(ey-y))%2) return ;   
    // ʱ�����꣬���ж��Ƿ��յ㲢����  
    if(t==0)   
    {  
        if(x==ex&&y==ey)  {flag=1; return ;}  
        else { return ;  }  
    }  
    /** 2���ݹ��ĸ����� */  
    for(int i=0;i<4;i++)                   
    {  
        int nx=x+d[i][0],ny=y+d[i][1];//��һλ��  
        // �ų���1Խ�磬2����'.'�����յ�  
        if (nx>0&&nx<=n&&ny>0&&ny<=m&&(map[nx][ny]=='.'||map[nx][ny]=='D'))  
        {  
            map[nx][ny]='X';//��ǵ�ǰ���߹�           
            dfs( nx,ny,t-1) ;// ʱ��-1���ݹ���һ��  
            map[nx][ny]='.';//��ԭ״̬           
        }  
  
    }    
    return ;    
}    
int main()    
{    
    char str[10];      
    int t;    
    while (scanf("%d%d%d",&n,&m,&t)!=EOF)    
    {       
        if(n==0&&m==0&&t==0) return 0;    
        for (int i=1;i<=n;i++)    
        {    
            scanf("%s",str);    
            for (int j=1;j<=m;j++)    
            {    
                map[i][j]=str[j-1];       
                if(map[i][j]=='S')  sx=i,sy=j;    
                else if(map[i][j]=='D') ex=i,ey=j;    
            }    
        }             
        flag=0;    
        dfs(sx,sy,t);    
        if(flag==0) printf("NO\n");    
        else printf("YES\n");     
    }    
    return 0;    
}  