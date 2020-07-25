#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1000000007;
ll countStrings(ll N, ll S)
{

    ll dp[N + 1][S];
    memset(dp, 0, sizeof(dp));
    for(ll i=0;i<S;i++){
        if(i==0||i==1) dp[1][i]=1; else dp[1][i]=0;
    }

    for (ll i = 2; i <= N; i++){
     for(ll j=0;j<S;j++){
        dp[i][0] = (dp[i][0]+dp[i-1][j])% MOD;
    }
    for(ll j=1;j<S;j++){
        dp[i][j] = dp[i - 1][j-1] % MOD;
    }
   }
   ll ans=0;
   for(ll j=0;j<S;j++) ans=(ans+dp[N][j])%MOD;
    return ans;
}
int main()
{

    ll N,S,T;
    cin>>T;
    while(T--){
    cin>>N>>S;
    if(N==1) {cout<<1<<'\n';continue;}
    N=N-1;
    cout << countStrings(N,S)<<'\n';
    }
    return 0;
}
