#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n;
    long maxTime = 0;
    int tmp;
    cin >> t;
    while (t-->0){
        cin >> n;
        maxTime = n;
        if (n == 1){
            cout << 1 << endl;
            continue;
        }
        for (int i = 0;i < n-1;i++){
            cin >> tmp;
            if (i + 1 + tmp > maxTime) maxTime = i + 1 + tmp;
        }
        for (int i = 0;i < n-1;i++){
            cin >> tmp;
            if (i + 1 + tmp > maxTime) maxTime = i + 1 + tmp;
        }
        cout << maxTime << endl;
    }
    return 0;
}
