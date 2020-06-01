#include<bits/stdc++.h>
using namespace std;
#define maxnum 100
int main()
{
    int tu[maxnum][maxnum]={0};
    bool ifuse[maxnum]={0};
    vector<int> currjuli(maxnum,999);
    /*n:the number of vertex
      m:the number of edge
      v:the first v*/
    int v,n,m,v1,v2,w;
    cin>>n>>m>>v;
    for(int i=0;i<m;i++)
    {
        cin>>v1>>v2>>w;
        tu[v1][v2]=w;
    }
    int currv=v,nextv=0,mine=999;
    ifuse[v]=1;
    for(int i=0;i<n;i++)
    {
        if(tu[currv][i]!=0)
        {
            currjuli[i]=tu[currv][i];
            if(currjuli[i]<mine)
            {
                nextv=i;
                mine=currjuli[i];
            }
        }
    }
    /*currv表示当前选择的顶点，
      nextv为下一个选择的顶点，
      mine为当前最小顶点的权值*/
    currv=nextv;mine=999;
    for(int i=1;i<n;i++)//遍历n-1次，寻找n-1个下一个点
    {
        //当前的点被使用
        ifuse[currv]=1;
        for(int j=0;j<n;j++)
        {
            //遍历当前点的每个边
            if(tu[currv][j]!=0&&j!=currv)
            {//更新每个顶点的最小值
                if(currjuli[currv]+tu[currv][j]<currjuli[j])
                    currjuli[j]=currjuli[currv]+tu[currv][j];
            }
            //找到下一个最小的，没有用过的点，存到nextv中
            if(currjuli[j]<mine&&ifuse[j]==0)
            {
                nextv=j;
                mine=currjuli[j];
            }
        }
        currv=nextv;mine=999;
    }
    cout<<"----------------------"<<endl;
    for(int i=0;i<n;i++)
        cout<<setw(4)<<i;
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        if(i==v)
            cout<<setw(4)<<0;
        else if(currjuli[i]==999)
            cout<<setw(4)<<"INF";
        else
        cout<<setw(4)<<currjuli[i];
    }

}
