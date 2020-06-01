#include<iostream>
using namespace std;
float mbq,v[4]={0.25,0.1,0.05,0.01};
int numb[4],f=0,x[4],tmpx[4]={0};
void huisu(float currq,int bh)
{
    if(currq>mbq||bh>=4)
        return;
    if(currq==mbq)
    {
        f=1;
        for(int i=0;i<4;i++)
            x[i]=tmpx[i];
    }
    for(int j=0;j<=numb[bh];j++)
    {
        huisu(currq,bh+1);
        tmpx[bh]=j;
        huisu(currq+v[bh]*tmpx[bh],bh+1);
        tmpx[bh]=0;
    }
}
int main()
{
    while(cin>>mbq>>numb[0]>>numb[1]>>numb[2]>>numb[3])
    {
        f=0;
        huisu(0,0);
        if(f==0)
            cout<<"NO EXACT CHANGE"<<endl;
        else
        {
            for(int i=0;i<4;i++)
                cout<<x[i]<<' ';
            cout<<endl;
        }
    }
}
