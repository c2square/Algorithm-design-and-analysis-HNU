#include<bits/stdc++.h>
using namespace std;
int tmp[100000];
void Merge(int a[],int r,int mid,int l)
{
    int x1=r,x2=mid+1;          //x1为前半段的指针，x2为后半段的指针
    for(int i=0;i<=l-r;i++)     //遍历每个子数组，用插入排序
    {
        if(x2>l)                //x2的值超过边界
        {
            tmp[i]=a[x1];
            x1++;
        }
        else if(x1>mid)         //x1的值超过边界
        {
            tmp[i]=a[x2];
            x2++;
        }
        else if(a[x1]<a[x2])    //插入排序，结果存到tmp中
        {
            tmp[i]=a[x1];
            x1++;
        }
        else if(a[x1]>=a[x2])
        {
            tmp[i]=a[x2];
            x2++;
        }
    }
    for(int i=0;i<=l-r;i++)      //整合成一个数组
        a[r+i]=tmp[i];
}
void guibing(int a[],int r,int l)
{
    if(l==r)    //只有一个数组时，返回
    {
        return;
    }
    else
    {
        int mid=(r+l)/2;
        guibing(a,r,mid);   //继续分解成两个子数组
        guibing(a,mid+1,l);
        Merge(a,r,mid,l);   //合并两个子数组
    }
}
int main()
{
    int n,a[100000];
    string infile[3]={"in100.txt","in1k.txt","in10K.txt"},
    ofile[3]={"out100.txt","out1k.txt","out10K.txt"};
    for(int t=0;t<3;t++)
    {
        ifstream indata(infile[t],ios::in);
        ofstream outfile(ofile[t],ios::trunc);
        clock_t start,end,over;
        start=clock();end=clock();over=end-start;

        indata>>n;
        for(int i=0;i<n;i++)
            indata>>a[i];

        start=clock();
        guibing(a,0,n-1);

        end=clock();

        for(int i=0;i<n;i++)
            outfile<<a[i]<<' ';
        cout<<"测试数据规模 "<<infile[t]<<endl;
        printf("The time is %6.3f\n",(double)(end-start-over)/CLK_TCK);
        cout<<"-----------------------------------"<<endl;
    }

}
