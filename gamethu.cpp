#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll n;
string s;
void solve(string x){
    ll i,j;
    for(i=0;i<x.size();i++){
        if('A'<=x[i] && x[i]<='Z'){
            x[i] = (x[i]-'A')+'a';
        }
    }
    // cout<<x<<'\n';
    string tiento="",hauto="";
    for(i=0;i<s.size();i++) if(s[i]!='*') tiento=tiento+s[i];
    else break;
    for(i=s.size()-1;i>=0;i--) if(s[i]!='*') hauto=hauto+s[i];
    else break;
    reverse(hauto.begin(),hauto.end());
    // cout<<tiento<<" --- "<<hauto<<'\n';
    if(x.size()<tiento.size()+hauto.size()){
        cout<<"NO\n";
        return;
    }
    string check_tiento="",check_hauto="";
    for(i=0;i<tiento.size();i++) check_tiento = check_tiento + x[i];
    // cout<<check_tiento<<" "<<'\n';
    if(check_tiento!=tiento){
        cout<<"NO\n";
        return;
    }
    for(i=x.size()-1;i>=x.size()-1-hauto.size()+1;i--) check_hauto = check_hauto + x[i];
    reverse(check_hauto.begin(),check_hauto.end());
    // cout<<check_hauto<<" "<<'\n';
    if(check_hauto!=hauto){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    return;
}
int main(){
    cin>>n;
    cin>>s;
    for(ll i=0;i<s.size();i++){
        if('A'<=s[i] && s[i]<='Z'){
            s[i] = (s[i]-'A')+'a';
        }
    }
    // cout<<s<<'\n';
    string tmp;
    while(n--){
        cin>>tmp;
        solve(tmp);
    }
}
