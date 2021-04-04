#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define maxn 21
ll a[maxn];
int main(){
    ll n,k;
    cin>>n;
    for(ll i=0;i<n;i++) cin>>a[i];
    cin>>k;
    for(ll i=0;i<(1<<n);i++){
        ll sum=0;
        for(ll j=0;j<n;j++)
        if(i&(1<<j)) sum=sum+a[j];
        if(sum==k){
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}
