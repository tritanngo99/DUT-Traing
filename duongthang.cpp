#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define EPSILON numeric_limits<double>::epsilon()

bool compareDoubles(double A, double B)
{
    double diff = A - B;
    return (diff < EPSILON) && (-diff < EPSILON);
}

ll numberOfTringles(ll a[], ll b[], ll c[], ll n)
{
    double slope[n];
    for (ll i = 0; i < n; i++)
        slope[i] = (a[i] * 1.0) / b[i];
    sort(slope, slope + n);
    ll count[n], k = 0;
    ll this_count = 1;
    for (ll i = 1; i < n; i++)
    {
        if (compareDoubles(slope[i], slope[i - 1]))
            this_count++;
        else
        {
            count[k++] = this_count;
            this_count = 1;
        }
    }
    count[k++] = this_count;
    ll sum1 = 0;
    for (ll i = 0; i < k; i++)
        sum1 += count[i];
    ll sum2 = 0;
    ll temp[n];
    for (ll i = 0; i < k; i++)
    {
        temp[i] = count[i] * (sum1 - count[i]);
        sum2 += temp[i];
    }
    sum2 /= 2;
    ll sum3 = 0;
    for (ll i = 0; i < k; i++)
        sum3 += count[i] * (sum2 - temp[i]);
    sum3 /= 3;

    return sum3;
}
int main()
{
    // lines are stored as arrays of a, b
    // and c for 'ax+by=c'
    // freopen("ok.txt","r",stdin);
    ll n;
    cin >> n;
    ll a[n];
    ll b[n];
    ll c[n];
    for (ll i = 0; i < n; i++)
        cin >> a[i] >> b[i] >> c[i], c[i] = -c[i];
    cout << numberOfTringles(a, b, c, n);

    return 0;
}
