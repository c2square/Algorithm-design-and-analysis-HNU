#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000],minduan=0;
struct Duan
{//段的信息
    Duan()
    {
        v=0;
        b=0;
        e=0;
        num=0;
    }
    int v,b,e,num;
};
/*寻找最大子段和的段*/
vector<Duan> duan(100);
int find_md(vector<Duan> d,int n)
{
    int res=0,resv=0;
    for(int i=1;i<=n;i++)
    {
        if(d[i].v>resv)
        {
            resv=d[i].v;
            res=i;
        }
    }
    return res;
}
/*将最大子段拆解成2个子段*/
void adduan(vector<Duan> &duan,int currdn)
{
    /*zjd：  分隔该段的元素
      dmin： 2段的最大值
      rlvel,rrvel：最终的左，右段和
    */
    int zjd=0,dmin=9999,rlvel,rrvel;
    //i代表分段点
    for(int i=duan[currdn].b;i<duan[currdn].e;i++)
    {
        int lvel=0,rvel=0;
        //计算左右两段的子段和
        for(int k=duan[currdn].b;k<=i;k++)
            lvel+=a[k];
        for(int k=i+1;k<=duan[currdn].e;k++)
            rvel+=a[k];
        //如果最大子段和符合要求，更新
        if(dmin>max(rvel,lvel))
        {
            dmin=max(rvel,lvel);
            zjd=i;
            rlvel=lvel;
            rrvel=rvel;
        }
    }
    //将最终分段的结果传入duan[]里
    Duan tmp;
    tmp.b=zjd+1;tmp.e=duan[currdn].e;tmp.v=rrvel;
    tmp.num=duan[currdn].e-zjd;

    duan[currdn].e=zjd; duan[currdn].v=rlvel;
    duan[currdn].num=zjd-duan[currdn].b+1;
    //插入新的段
    duan.insert(duan.begin()+currdn+1,tmp);
}
int main()
{
    cin>>n>>m;
    //初始化第一个段，包含全部元素
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        duan[1].v+=a[i];
    }
    duan[1].num=n;  duan[1].b=0;    duan[1].e=n-1;
    int currdn=1;
    minduan=duan[currdn].v;
    /*开始分段，i代表当前应当分的段数，从应分2段开始*/
    for(int i=2;i<=m;i++)
    {
        //找到值最大的段
        currdn=find_md(duan,i-1);
        //如果最大段的里面元素个数为1，则其为最终结果
        if(duan[currdn].num==1)
        {
            minduan=duan[currdn].v;
            break;
        }
        else
        {
            //增加把我们的选中的段分2段
            adduan(duan,currdn);
            //更新最大值
            currdn=find_md(duan,i);
            minduan=duan[currdn].v;
        }
    }
    cout<<"duan message"<<endl;
    for(int i=1;i<=m;i++)
        cout<<duan[i].v<<' ';
    cout<<endl<<"max value in duan"<<endl<<minduan<<endl;

}
