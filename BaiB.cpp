
#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
bool isPrime[maxn+1];
void sieve(int N) {
    for(int i = 0; i <= N;++i) {
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 2; i * i <= N; ++i) {
         if(isPrime[i] == true) {

             for(int j = i * i; j <= N; j += i)
                 isPrime[j] = false;
        }
    }
}
bool solve(string s){
  map<char,int> mapping;
  map<char,int>::iterator it;
  mapping.clear();
  for(int i=0;i<s.size();i++) mapping[s[i]]++;
  if(!isPrime[mapping.size()]) return false;
  for(it=mapping.begin();it!=mapping.end();it++){
    if(!isPrime[it->second]) return false;
  }
  if(isPrime[mapping.size()]) return true;
}
int main(){
    string s;
    int t;
  sieve(maxn);
  cin>>t;
  while(t--){
     cin>>s;
     if(solve(s)) cout<<"YES\n"; else cout<<"NO\n";
  }
  return 0;
}
