#include<iostream>
using namespace std;
int n,c,bestp;//物品个数,背包容量,最大价值
int p[10000],w[10000],x[10000],bestx[10000];//物品的价值,物品的重量,物品的选中情况

//cp当前已放入的总价值，cw当前已放入的总重量
void backtrack(int i,int cp,int cw)
{
    if(i>n)
    {
        if(cp>bestp)
        {
            bestp=cp;
            for(i=1;i<=n;i++) bestx[i]=x[i];
        }
    }
    else
    {
        //每一层的物品都可以选择放入或者不放，0表示不放，1表示放入
        for(int j=0;j<=1;j++)
        {
            x[i]=j;
            if(cw+x[i]*w[i]<=c)
            {
                cw+=w[i]*x[i];
                cp+=p[i]*x[i];
                backtrack(i+1,cp,cw);
                cw-=w[i]*x[i];
                cp-=p[i]*x[i];
            }
        }
    }
}

int main()
{
    bestp=0;
    cin>>c>>n;
    for(int i=1;i<=n;i++) cin>>w[i]>>p[i];
    backtrack(1,0,0);
    cout<<bestp<<endl;
    for(int i=1;i<=n;i++) cout << bestx[i] << " ";
}
