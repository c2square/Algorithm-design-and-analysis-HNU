#include<bits/stdc++.h>
using namespace std;
int tree[100][100]={0},v[100]={0},sum[100]={0};
int n,s,e;
void qiu(int k,int T)
{
    for(int i=1;i<=n;i++)
    {
        //遍历k的每个子节点i（除了k的父节点T）
        if((tree[k][i]==1)&&(i!=T))
        {
            qiu(i,k);
            //大于0才相加，小于0舍弃
            if(sum[i]>0)
            {
                sum[k]+=sum[i];
            }

        }
    }
    sum[k]+=v[k];
}
int main()
{

    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    for(int i=1;i<n;i++)
    {
        cin>>s>>e;
        tree[s][e]=tree[e][s]=1;
    }
    //传入任意节点都可以，T默认为自身
    qiu(1,1);
    sort(sum+1,sum+n+1);
    cout<<sum[n];
}
