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
////��C��A B���������еĵ��������x��y���ꡣ ͨ�����ɶ���õ�
//void Cal(double x1,double y1,double x2,double y2,double& x3,double& y3){
//    //AB�����ĵľ���
//    double dis=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
//    //�������Ĺ��ɵĵ��������ε����߳�
//    double len=sqrt((2*2) - (dis/2)*(dis/2));
//    double s,c;
//    //�����봹ֱ�ߵļнǵ�sinֵ
//    s=(y2-y1)/dis;
//    //�����봹ֱ�ߵļнǵ�cosֵ
//    c=(x2-x1)/dis;
//
//    //����C��x���� = AB�������ߵ��е�x���� - ����ĳ���
//    x3=(x1+x2)/2-len*s;
//    //����C��y���� = AB�������ߵ��е�y���� + �ٵĳ���
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
