#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    long long n,a,b,tmp;
    cin>>n;
    while(n--)
    {
        cin>>a>>b;
        while(b!=0)
        {
            tmp=b;
            b=a%b;
            a=tmp;
        }
        cout<<a<<endl;
    }
}
