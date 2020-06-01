#include <bits/stdc++.h>
using namespace std;

const unsigned long maxshort = 65535L;
const unsigned long multiplier = 1194211693L;
const unsigned long adder = 12345L;
const int INF = 9999;

class RandomNumber{
private:
    // 当前种子
    unsigned long randSeed;
public:
    // 构造函数,默认值0表示由系统自动产生种子
    RandomNumber(unsigned long s = 0)
    {
        if(s == 0)
            randSeed = time(0);    //用系统时间产生种子
        else
            randSeed = s;
    }
    // 产生0 ~ n-1之间的随机整数

    unsigned short Random(unsigned long n)
    {
        randSeed = multiplier * randSeed + adder;
        return (unsigned short)((randSeed >> 16) % n);
    }

    // 产生[0, 1) 之间的随机实数
    double fRandom()
    {
        return Random(maxshort) / double(maxshort);
    }
};


// 交换a, b的值
template <typename Type>
void Swap(Type &a, Type &b)
{
    Type temp;
    temp = a;
    a = b;
    b = temp;
}

template <typename Type>
Type select(Type a[], int lt, int rt, int k)
{
    // 计算a[lt:rt]中第k小元素
    static RandomNumber rnd;
    while(true)
    {
        if(lt > rt)
            return a[lt];
        // 随机选择的划分基准
        int i = lt, j = lt+rnd.Random(rt-lt+1);
        Swap(a[i], a[j]);
        j = rt+1;
        Type pivot = a[lt];
        //以划分基准为轴作元素交换
        while(true)
        {
            while(a[++i] < pivot);
            while(a[--j] > pivot);
            if(i >= j)
                break;
            Swap(a[i], a[j]);
        }
        if(j - lt + 1 == k)
            return pivot;
        a[lt] = a[j];
        a[j] = pivot;
        // 对子数组重复划分过程
        if(j - lt + 1 < k)
            {
                k = k - j + lt - 1;
                lt = j + 1;
            }
        else
            rt = j - 1;
    }
}

template <typename Type>
Type Select(Type a[], int n, int k)
{
    // 计算a[0: n-1]中第k小元素
    // 假设a[n]是一个键值无穷大的元素
    if(k < 1 || k > n)
        cerr << "Wrong!" << endl;
    return select(a, 0, n-1, k);
}
int arr[1020],n;
int main()
{
    ifstream indata("in1k.txt",ios::in);
    indata>>n;
    for(int i=0;i<n;i++)
        indata>>arr[i];
    cout << Select(arr, n, 560) << endl;
}
