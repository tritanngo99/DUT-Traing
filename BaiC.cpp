#include<bits/stdc++.h>
#define ll long long
using namespace std;
int  main(){
  ll  n,se,fi,tmp;
  while(cin>>n){
    tmp = __builtin_popcount(n);
    if(tmp==1) {fi=(ll )log2(n);se=0;}
    else {
            fi=(ll )log2(n)+1;
            for(int i=0;i<30;i++){
                if((n>>i)&1) {se=fi-i;break;}
            }
    }
    fi=(ll)pow(2,fi);
   cout<<fi<<" "<<se<<'\n';
  }
  return 0;
}
