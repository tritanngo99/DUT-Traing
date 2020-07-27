#include <bits/stdc++.h>

using namespace std;

int findBestWay(string s, int l, int r){
    while (s[l] == s[r] && l < r){
        l++;
        r--;
    }
    if (l == r) return 0;
    if (s[l] < s[r]) return 0;
    return 1;
}

int main()
{
    int n;
    string s, t = "";
    cin >> n;
    cin >> s;
    int l = 0;
    int r = n - 1;
    if (n == 1){
        cout << s;
        return 0;
    }
    while (1){
        if (findBestWay(s, l, r) == 0){
            t = t + s[l];
            l++;
        } else {
            t = t + s[r];
            r--;
        }
        if (l == r){
            t = t + s[l];
            break;
        }
    }
    cout << t;
    return 0;
}
