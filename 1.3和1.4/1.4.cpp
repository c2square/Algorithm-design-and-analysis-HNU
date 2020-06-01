#include<bits/stdc++.h>
using namespace std;
struct DX
{
    float w,v,b;
}dx[1000];
bool cmp(DX d1,DX d2)
{
    if(d1.b<=d2.b)
        return false;
    return true;
}
int main()
{
    int n,W;
    float V=0,cw=0;
    string infile[4]={"in1.txt","in2.txt","in3.txt","in4.txt"};
    for(int t=0;t<4;t++)
    {
        ifstream indata(infile[t]);
        clock_t start,end,over;
        V=0;
        cw=0;
        indata>>W>>n;
        //cin>>W>>n;
        for(int i=0;i<n;i++)
        {
            indata>>dx[i].w>>dx[i].v;
            //cin>>w[i]>>v[i];
        }
        start=clock();
        for(int i=0;i<n;i++)
        {
            dx[i].b=dx[i].v/dx[i].w;
        }
        //dx为背包内的东西，先由b=v/w排序
        sort(dx,dx+n,cmp);
        //由b最大到最小开始放入背包
        for(int i=0;i<n;i++)
        {
            //背包装得下当前dx
            if(cw+dx[i].w<=W)
            {
                cw+=dx[i].w;
                V+=dx[i].v;
            }
            //装不下则去一部分
            else
            {
                V+=((W-cw)/dx[i].w)*dx[i].v;
            }
        }
        end=clock();
            cout<<V<<endl;
        over=end-start;
            printf("The time is %6.3f\n",(double)(end-start-over)/CLK_TCK);
            cout<<"-----------------------------------"<<endl;
    }
}
