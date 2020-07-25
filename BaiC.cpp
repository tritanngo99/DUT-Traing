#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000009
ll  po(ll  a,ll  n){
  ll  res = a , ans=1;
  while(n){
    if(n%2) ans=ans*res%mod;
    res=res*res%mod;
    n/=2;
  }
  return ans;
}
ll  f(ll  n){
  if(n%2) return -1;
  return 1;
}
int main(){
  //  cout<<po(2,3);
  ll  n,f1,f2,t,f3,f4,res;
  cin>>t;
  while(t--){
  cin>>n;
  f1=8*po(n,3)%mod;
  f2=6*po(n,2)%mod;
  f3=(16*n+9*(f(n)-1))%mod;
  f4=po(12,mod-2);
  res=(f1+f2+f3)%mod*f4%mod;
  cout<<res<<'\n';
  }
}
