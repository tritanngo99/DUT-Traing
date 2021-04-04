#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll testcase,N,K;
int main(){
    // freopen("ok.txt","r",stdin);
    cin>>testcase;
    while (testcase--)
    {
        cin>>N>>K;
        ll res=0;
        if(K%2==1){
            for(ll i=1;i<=(K-1)/2;i++){
             ll tmp1 = (N-i)/K+1;
             ll tmp2 = (N-K+i)/K+1;
            //  cout<<tmp1<<" "<<tmp2<<'\n';
             res=res+tmp1*tmp2;
            }
            ll kk = N/K;
            res=res+kk*(kk-1)/2;
        }
        else{
            for(ll i=1;i<(K)/2;i++){
             ll tmp1 = (N-i)/K+1;
             ll tmp2 = (N-K+i)/K+1;
            //  cout<<tmp1<<" "<<tmp2<<'\n';
             res=res+tmp1*tmp2;
            }
            ll kk = N/K;
            res=res+kk*(kk-1)/2;
            kk = (N-(K/2))/K+1;
            res=res+kk*(kk-1)/2;
        }
        cout<<res<<'\n';
    }
    return 0;
}
