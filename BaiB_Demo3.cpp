#include <bits/stdc++.h>
using namespace std;
int main()
{
    // freopen("data.inp", "r", stdin);
    // freopen("data.out", "w", stdout);

    int prices[6] = {1, 5, 10, 50, 100, 500};
    int amount[6];
    for (int i = 0; i < 6; ++i)
        cin >> amount[i];
    int x;
    cin >> x;
    int sum = 0;
    for (int i = 5; i >= 0; --i)
    {
        {
            sum += min(x / prices[i] + (x / prices[i] == 0 && x > prices[i]), amount[i]);
            x = x - min(x / prices[i] + (x / prices[i] == 0 && x > prices[i]), amount[i]) * prices[i];
        }
    }
    if (x != 0)
        cout << -1;
    else
    {
        cout << sum;
    }
}
