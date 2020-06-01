#include<iostream>
using namespace std;

int main()
{
    int n,m,piao[3][8],r[3]={0},t;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>m;
        r[0]=0;
        r[1]=0;
        r[2]=0;
        for(int j=0;j<m;j++)
        {
            //输入
            for(int k=0;k<8;k++)
            {
                cin>>t;
                if(t>4)
                    piao[0][k]=1;
                else
                    piao[0][k]=0;
                if(t==3||t==4||t==7||t==8)
                    piao[1][k]=1;
                else
                    piao[1][k]=0;
                if(t%2==0)
                    piao[2][k]=1;
                else
                    piao[2][k]=0;
            }

            t=0;
            //找到不相等的t
            while(piao[0][t]==r[0]&&piao[1][t]==r[1]&&piao[2][t]==r[2])
                t++;
            //修改r[k]
            for(int k=0;k<3;k++)
            {
                if(r[k]!=piao[k][t])
                {
                    if(r[k]==0)
                        r[k]=1;
                    else
                        r[k]=0;
                    break;
                }
            }
            for(int k=0;k<3;k++)
            {
                if(r[k]==0)
                    cout<<"N";
                else
                    cout<<"Y";
            }
            cout<<endl;
        }
        for(int k=0;k<3;k++)
            {
                if(r[k]==0)
                    cout<<"N";
                else
                    cout<<"Y";
            }
            cout<<endl;

    }
}
