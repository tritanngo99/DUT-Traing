#include <bits/stdc++.h>
#define dd double
#define ll long long
using namespace std;

vector<dd> v;
ll n,k;

bool check(dd x){
	ll cnt=0;
	for (auto it: v){
		cnt+=it/x;
	}
	
//	cout<<x<<" "<<cnt<<"\n";
	
	if (cnt>=k) return true;
	return false;
}

int main(){
//	freopen("input.inp","r",stdin);
	
	cin>>n>>k;
	v.resize(n);
	
	for (auto &it :v) cin>>it;
//	for (auto it: v) cout<<it<<" ";
//	cout<<"\n";
	
	dd lo=1,hi=1e5,ans=1;
	while (hi-lo>=pow(10,-3)){
		dd mid=(lo+hi)/2;
//		cout<<mid<<"\n";
		
		if (check(mid)) {
			lo=mid+0.001;
			ans=mid;
		}
		else hi=mid-0.001;
	}
	
	cout<<setprecision(2)<<fixed<<ans<<"\n";
}
