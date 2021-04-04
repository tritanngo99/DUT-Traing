#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll hour,minute,second;
int main(){
    cin>>hour>>minute>>second;
    if(second==59){
    second=0;
    minute+=1;
    if(minute==60){
        minute=0;
        hour+=1;
        if(hour==24){
            hour=0;
        }
        else{
            hour+=0;}
    }
    else{
        minute+=0;}
    }
else{
    second+=1;}
  cout<<hour<<":"<<minute<<":"<<second;
  return 0;
}
