/*
问题描述：在一个按照南北方向划分成规整街区的城市里，
n个居民点分布在一条直线上的n个坐标点x1<x2<…<xn处。
居民们希望在城市中至少选择一个，但不超过k个居民点建立服务机构。
在每个居民点xi处，服务需求量为wi≥0，在该居民点设置服务机构的费用为ci≥0。
假设居民点xi到距其最近的服务机构的距离为di,则居民点xi的服务费用为wi·di。
建立k个服务机构的总费用为A+B。A是在k个居民点设置服务机构的费用的总和；
B是n个居民点服务费用的总和。
*/
#include<bits/stdc++.h>
using namespace std;
struct city
{
    int p,w,c,zh;
}x[100];
int n,k;
int A[100][100]={0},ifjian[100]={0},tmp=0,mincost=99999,mini=0;
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>x[i].p>>x[i].w>>x[i].c;
        x[i].zh=0;
    }
    for(int t=1;t<=k;t++)//t个服务站
    {int tmpmin=9999;
        for(int i=0;i<n;i++)
        {//遍历每个不是服务站的地方
            if(x[i].zh!=1)
            {tmp=0;
                for(int j=0;j<n;j++)
                {//计算其他地方到i服务站的总费用
                    if(x[j].zh!=1)
                    {
                        if(i==j)
                            tmp+=x[j].c;
                        else
                        {
                            if(t!=1)
                                tmp+=min(A[t-1][j],abs(x[j].p-x[i].p)*x[j].w);
                            else
                                tmp+=abs(x[j].p-x[i].p)*x[j].w;
                        }
                    }
                    else
                        tmp+=x[j].c;
                }
            }
            //找到代价最小的城市
            if(tmp<tmpmin)
            {
                mini=i;
                tmpmin=tmp;
            }
        }
        //更新加入代价最小的城市，对每个城市造成的代价
        x[mini].zh=1;
        for(int i=0;i<n;i++)
        {
            if(x[i].zh!=1)
            {
                if(t!=1)
                    A[t][i]=min(A[t-1][i],abs(x[i].p-x[mini].p)*x[i].w);
                else
                    A[t][i]=abs(x[i].p-x[mini].p)*x[i].w;
            }
            else
                A[t][i]=x[i].c;
        }
        //更新最小值
        mincost=min(mincost,tmpmin);
    }
    cout<<mincost;
}
