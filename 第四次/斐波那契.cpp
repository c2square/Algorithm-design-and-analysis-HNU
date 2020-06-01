#include <bits/stdc++.h>
using namespace std;
const int N = 40;
const int N2 = 15000;
int fib[N], f[N2];
void maketable()
{
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2; i < N; i++)
        fib[i] = fib[i - 2] + fib[i - 1];

    f[0] = 0;
    f[1] = 1;
    for(int i = 2; i < N2; i++)
        f[i] = (f[i - 2] + f[i - 1]) % 10000;
}

int main()
{
    maketable();

    int n;
    while(cin >> n) {
        if(n < N)
            cout << fib[n] << endl;
        else {
            double x = log10(1 / sqrt(5)) + n * log10((1 + sqrt(5)) / 2.0);
            double y = x - (int)(x) + 3;
            int ans = (int)pow(10.0, y);
            cout << ans << "...";
            printf("%04d\n", f[n % N2]);
        }
    }

    return 0;
}
