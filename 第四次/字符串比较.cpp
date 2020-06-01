#include<bits/stdc++.h>
using namespace std;
int dist(char a,char b)
{
    return (int)abs(a-b);
}
int minx(int a,int b, int c)
{
    return min(min(a,b),c);
}
int main()
{
    string s1,s2;
    int k,val[50][50]={{0,0}};
    cin>>s1>>s2>>k;
    for(int i=0;i<=s1.size();i++)
    {
        for(int j=0;j<=s2.size();j++)
        {
            //不为边界
            if(i!=0&&j!=0)
            {
                val[i][j]=minx(val[i-1][j]+k,
                               val[i][j-1]+k,
                               val[i-1][j-1]+dist(s1[i-1],s2[j-1]));
            }
            //边界值处理
            else if(i==0&&j!=0)
                val[i][j]=j*k;
            else if(j==0&&i!=0)
                val[i][j]=i*k;
        }
    }
    cout<<val[s1.size()][s2.size()];
}
