#include<bits/stdc++.h>
using namespace std;
int n,c;
int s[100],x[100]={0},tmpx[100]={0};
void huisu(int i,int currn)
{
    if(currn==c)//当前和currn=c目标和
    {
        for(int i=0;i<n;i++)
            x[i]=tmpx[i];
        return;
    }
    if(i>=n)//超过元素个数
        return;
    //不取x[i]
    huisu(i+1,currn);
    //已经超过目标和，直接返回
    if(currn+x[i]>c)
        return;
    else//取x[i]
    {
        tmpx[i]=1;
        huisu(i+1,currn+s[i]);
        tmpx[i]=0;
    }
}
int main()
{
    int f=0;
    cin>>n>>c;
    for(int i=0;i<n;i++)
        cin>>s[i];
    huisu(0,0);
    for(int i=0;i<n;i++)
    {
        if(x[i])
        {
            cout<<s[i]<<' ';
            f=1;
        }
    }
    if(!f)
        cout<<"No solution!";
}
