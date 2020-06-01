#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
struct center
{
    double x;
    double y;
};
bool cmp(center a,center b)
{
    return a.x<b.x;
}
void qiu(center a,center b,center &c1)
{
    double dis=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
    double len=sqrt(4-(dis/2)*(dis/2));
    double s,c;
    s=(b.y-a.y)/dis;
    c=(b.x-a.x)/dis;
    c1.x=(a.x+b.x)/2-len*s;
    c1.y=(a.y+b.c)/2+len*c;
}
int main()
{
    int n;
    center cent[100];
    int testn;
    cin>>testn;
    for(int test=1;test<=testn;test++)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>cent[i].x;
            cent[i].y=1.0;
        }
        sort(cent,cent+n;cmp);
        while(n>1)
        {

            for(int k=0;k<n-1;k++)
            {
                qiu(cent[k],cent[k+1],cent[k])
            }
            n--;
        }
        cout<<test<<": "<<setprecision(4)<<fixed()<<cent[0].x<<' '<<cent[0].y<<endl;
    }
}
//#include <stdlib.h>
//#include <iostream>
//#include <stdio.h>
//#include <math.h>
//#include <algorithm>
//using namespace std;
//
//struct Center{
//   double x;
//   double y;
//};
//
//bool cmp(Center a, Center b){
//   return a.x < b.x;
//}
////求C与A B两个球相切的第三个球的x，y坐标。 通过勾股定理得到
//void Cal(double x1,double y1,double x2,double y2,double& x3,double& y3){
//    //AB两球心的距离
//    double dis=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
//    //三个球心构成的等腰三角形的中线长
//    double len=sqrt((2*2) - (dis/2)*(dis/2));
//    double s,c;
//    //中线与垂直线的夹角的sin值
//    s=(y2-y1)/dis;
//    //中线与垂直线的夹角的cos值
//    c=(x2-x1)/dis;
//
//    //球心C的x坐标 = AB球心连线的中点x坐标 - 多出的长度
//    x3=(x1+x2)/2-len*s;
//    //球心C的y坐标 = AB球心连线的中点y坐标 + 少的长度
//    y3=(y1+y2)/2+len*c;
//}
//
//int main()
//{
//    int n;
//    Center center[10];
//    n = -1;
//    int testN;
//    scanf("%d", &testN);
//    for(int test=1; test<= testN; test++){
//        scanf("%d", &n);
//        //cin >> n;
//        if(n == 0)
//          break;
//        for(int i=0; i<n; i++){
//            cin >> center[i].x;
//            center[i].y = 1.0;
//        }
//         sort(center, center+n, cmp);
//         while(n>1){
//          int k = 0;
//          for( ; k<n-1; k++){
//             Cal(center[k].x, center[k].y, center[k+1].x, center[k+1].y, center[k].x, center[k].y);
//          }
//          n--;
//        }
//        printf("%d: %.4lf %.4lf\n", test, center[0].x, center[0].y);
//        //cout << center[0].x << " " << center[0].y << endl;
//    }
//
//    return 0;
//}
