#include <bits/stdc++.h>
using namespace std;
int main()
{
    int rs = 1;
    long long n;
    cin >> n;

    for (int i = 2; i <= 1000005; ++i)
    {
        if (n % i == 0)
        {
            if (i == n)
                continue;
            rs = 0;
            break;
        }
    }
    if (n == 1)
        rs = 0;
    if (rs)
        cout << "YES";
    else
        cout << "NO";
}
