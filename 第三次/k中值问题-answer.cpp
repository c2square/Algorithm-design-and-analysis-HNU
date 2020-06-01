#include<bits/stdc++.h>
using namespace std;
#define maxnum 100
int wt[maxnum]={0},swt[maxnum]={0},
    x[maxnum],c[maxnum],ww[maxnum],
    dis[maxnum],opt1[maxnum][maxnum],opt2[maxnum][maxnum];
int n,m,w;
int res;
void readin()
{
    int w;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i]>>w>>c[i];
        ww[i]=w;
        wt[i]=wt[i-1]+w;
        dis[i]=x[i]-x[1];
        swt[i]=swt[i-1]+w*dis[i];
    }
}
int getw1(int j,int m)
{
    return (swt[m]-swt[j])-(wt[m]-wt[j])*dis[j];
}
int getw2(int j,int m)
{
    return (wt[m-1]-wt[j])*dis[m]-(swt[m-1]-swt[j]);
}
void comp()
{
    int i,j,k,tmp;
    //opt2[1][j]
    for(j=1;j<=n;j++)
        opt2[1][j]=c[j]+getw2(0,j);
    //opt1[1][j]
    for(j=1;j<=n;j++)
    {
        opt1[1][j]=opt2[1][1]+getw1(1,j);
        for(k=2;k<=j;k++)
        {
            tmp=opt2[1][k]+getw1(k,j);
            if(opt1[1][j]>tmp)
                opt1[1][j]=tmp;
        }
    }
    for(i=2;i<=m;i++)
    {   //opt2[i][j]
        for(j=i;j<=n;j++)
        {
            opt2[i][j]=opt1[i-1][i-1]+getw2(i-1,j);
            for(k=i;k<j;k++)
            {
                tmp=opt1[i-1][k]+getw2(k,j);
                if(opt2[i][j]>tmp)
                opt2[i][j]=tmp;
            }
            opt2[i][j]+=c[j];
        }
        //opt1[i][j]
        for(j=i;j<=n;j++)
        {
            opt1[i][j]=opt2[i][i]+getw1(i,j);
            for(k=i+1;k<=j;k++)
            {
                tmp=opt2[i][k]+getw1(k,j);
                if(opt1[i][j]>tmp)
                    opt1[i][j]=tmp;
            }
        }
    }
}
int solution()
{
    int tmp=opt1[1][n];
    for(int i=2;i<=m;i++)
    if(opt1[i][n]<tmp)
        tmp=opt1[i][n];
        return tmp;
}
int main()
{
    readin();
    comp();
    cout<<solution();

}
