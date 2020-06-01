#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,W,w[1000],v[1000],b[1000]={0};
    string infile[4]={"in1.txt","in2.txt","in3.txt","in4.txt"};
    for(int t=0;t<4;t++)
    {
        ifstream indata(infile[t]);
        clock_t start,end,over;

        indata>>W>>n;
        //cin>>W>>n;
        for(int i=1;i<=n;i++)
        {
            indata>>w[i]>>v[i];
            //cin>>w[i]>>v[i];
        }
        for(int i=0;i<=W;i++)
            b[i]=0;
        start=clock();
        //遍历每个元素
        for(int i=1;i<=n;i++)
            //背包载重从W-当前元素的重量
            for(int j=W;j>=w[i];j--)
            {
                /*当前元素为i，载重为j时
                  当前价值为2种情况
                  不取当前元素b[j]
                  取当前元素b[j-w[i]]+v[i]
                  两者取最大*/
                b[j]=max(b[j],b[j-w[i]]+v[i]);
                //b[j-w[i]]代表载重为j-w[i]时的最大价值
            }
        end=clock();
            cout<<b[W]<<endl;
        over=end-start;
            printf("The time is %6.3f\n",(double)(end-start-over)/CLK_TCK);
            cout<<"-----------------------------------"<<endl;
    }

}
