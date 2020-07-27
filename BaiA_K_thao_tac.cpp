#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll  t,n,k,s,tmp,x;
int main(){
    cin>>t;
    while(t--){
    priority_queue<ll ,vector<ll >> q;
    cin>>n>>k;
    s=0;
    for(ll  i=0;i<n;i++){
        cin>>x;
        q.push(x);
    }
    while(k--){
        tmp=q.top();
        s=s+tmp;
        q.pop();
        q.push((ll )ceil(tmp/2));
    }
    cout<<s<<'\n';
    }
}
