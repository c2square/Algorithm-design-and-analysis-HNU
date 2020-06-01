#include<bits/stdc++.h>
using namespace std;
int zuida(int a[],int b,int e)
{
    int mid=(e+b)/2;    //中间值
    if(mid==e)          //表示数组只有2个元素
    {                   //返回较大的那个
        if(a[e]>a[b])
            return a[e];
        else
            return a[b];
    }
    else                //数组元素多于2
    {
        int x1=zuida(a,b,mid);  //前一组数组中的最大值
        int x2=zuida(a,mid+1,e);//后一组数组中的最大值
        if(x1>x2)               //返回较大的那个
            return x1;
        else
            return x2;
    }
}
int zuixiao(int a[],int b,int e)
{
    int mid=(e+b)/2;
    if(mid==e)
    {
        if(a[e]<a[b])
            return a[e];
        else
            return a[b];
    }
    else
    {
        int x1=zuixiao(a,b,mid);
        int x2=zuixiao(a,mid+1,e);
        if(x1<x2)
            return x1;
        else
            return x2;
    }
}
int main()
{
    int n,a[100000],mx=0,mn=0;
    string infile[3]={"in100.txt","in1k.txt","in10K.txt"};
    for(int t=0;t<3;t++)
    {
        ifstream indata(infile[t],ios::in);
        clock_t start,end,over;
        start=clock();end=clock();over=end-start;

       indata>>n;
        for(int i=0;i<n;i++)
            indata>>a[i];
        start=clock();
        mx=zuida(a,0,n-1);
        mn=zuixiao(a,0,n-1);
        end=clock();

        cout<<" 测试数据规模 "<<infile[t]<<endl;
        cout<<" 最大："<<mx<<' '<<" 最小："<<mn<<endl;
        printf("The time is %6.3f\n",(double)(end-start-over)/CLK_TCK);
        cout<<"-----------------------------------"<<endl;
    }

}
