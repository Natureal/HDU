////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-28 11:08:56
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1392
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:296KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
//͹���������հ汾
typedef struct point//������Ľṹ��
{
    int x,y;
}point;
point p[105];
int n;
bool cmpx(point a,point b)//���������µ�ʱ�õıȽϺ���
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}
int cross(point p1,point p2,point p0)//����������������ΪP0P1��P0P2
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
bool cmp(point a,point b)//sort������cmp����������������
{
    int k=cross(a,b,p[0]);
    if(k==0)             //�����һ������ȡx����С���Ǹ���
        return a.x<b.x;
    return k>0;          //�ж�ǰһ����Ľ��Ƿ�Ⱥ���ĵ�С
}
double dis(point a,point b)//��������ľ���
{
    double  tx=1.0*b.x-a.x;
    double  ty=1.0*b.y-a.y;
    return sqrt(tx*tx+ty*ty);
}
int main()
{
    //freopen("in","r",stdin);
    while(scanf("%d",&n)!=EOF && n)
    {
        int k=-1;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&p[i].x,&p[i].y);
            if(k==-1||cmpx(p[i],p[k]))
            {
                k=i;
            }
        }
        if(n==1)//��Ŀ��Ҫ���ر��жϣ���ͬ
        {
            printf("0.00\n");
            continue;
        }
        if(n==2)
        {
            printf("%.2lf\n",dis(p[0],p[1]));
            continue;
        }
        swap(p[0],p[k]);//����С�ĵ���P��0������λ��
        sort(p+1,p+n,cmp);//���սǽ�������
        int t=2;          //����������Graham
        for(int i=2;i<n;i++)//i�ĳ�ֵҪ��tһ��
        {
            while(t>1&&cross(p[t-2],p[t-1],p[i])<=0) t--;//��������ת����ջ
            p[t++]=p[i];//ֱ���ܹ���ת
        }
        //����Graham������t-1�������һ��Ԫ��
        double sum=0;
        p[t]=p[0];//����
        for(int i=0;i<t;i++)//����͹���ܳ�
        {
            sum+=dis(p[i],p[i+1]);
        }
        printf("%.2lf\n",sum);
    }
    return 0;
}
