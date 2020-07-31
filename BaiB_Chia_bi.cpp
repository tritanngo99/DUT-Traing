#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 1005
ll table[maxn][maxn],tmp;
ll N,M,mod,res;
void f(ll sum, ll largestNumber){
    ll i,j;

    for (i=1;i<=sum;i++){
        for (j=1;j<=largestNumber;j++){
            if (i-j<0){
                table[i][j]=table[i][j-1]%mod;
                continue;
            }
            table[i][j]=(table[i][j-1]%mod+table[i-j][j]%mod)%mod;
        }
    }

    //return table[sum][largestNumber];
}

int main(){
    cin>>N>>M>>mod;
    ll sum = N;
    ll largestNumber = M;
    ll i;

    for (i=0;i<=sum;i++)
        table[i][0]=0;
    for (i=1;i<=largestNumber;i++)
        table[0][i]=1;

    f(sum,largestNumber);
    tmp = table[N][M];
    cout<<tmp<<'\n';
   // for(ll i=1;i<=M;i++) res=(res+table[sum][i])%mod;
    //cout<<res;
return 0;
}
