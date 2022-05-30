#include<bits/stdc++.h>
using namespace std;
int n,k,s,a[32],cmin;
long long res;

void attempt(int t, int sum, int cur){
    if(sum+(k-t+1)*a[cur+1]> s) return;
    if(t>k){
        if(sum == s){
            res++;
        }
        return;
    }
    for(int i = cur+1; i <=n-k+t;i++){

            attempt(t+1,sum+a[i],i);

    }
}

int main(){
    cmin = 1e9;
    res = 0;
    cin>>n>>k>>s;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    attempt(1,0,0);
    cout<<res;
}
