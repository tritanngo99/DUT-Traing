#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,c1,c2,c3,res,x;
int main(){
   cin>>n;
   for(int i=0;i<n;i++){
     cin>>x;
     if(x==1) c1++; else if(x==2) c2++; else if(x==3) c3++;
   }
   res=((c1 * (c1-1) * (c1-2)) / 6) * 3 + ((c1 * (c1-1)) / 2) * c2 * 2 + ((c1 * (c1-1)) / 2) * (n - c1 - c2) + c1 * ((c2 * (c2-1)) / 2) + c1 * c2 * c3;
   cout<<res;
   return 0;

}
