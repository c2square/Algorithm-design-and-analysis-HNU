#include<bits/stdc++.h>
using namespace std;
struct HD
{
    int s,e;
}hd[100];
bool cmp(HD h1,HD h2)
{
    if(h1.s<h2.s)
        return true;
    return false;
}
int main()
{
    int n,gs=1;
    bool ap;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>hd[i].s>>hd[i].e;
    sort(hd,hd+n,cmp);
    for(int i=1;i<n;i++)
    {
        //ap表示能否公用（=1为可公用）
        ap=0;
        for(int j=0;j<i;j++)
        {
            if(hd[i].s>=hd[j].e)
            {
                ap=1;
                //更新末尾值，防止公用的活动重复计算
                hd[j].e=hd[i].e;
            }
        }
        if(!ap)
            gs++;
    }
    cout<<gs;
}
