#include<bits/stdc++.h>
#include<math.h>
using namespace std;

float solve(float bot, float top){
    float mid = (bot+top)/2;
    if((top-bot)<1e-6) return mid;
    if((pow(mid,19) - pow(mid,2) - mid+1)<0) return solve(mid, top);
    if((pow(mid,19) - pow(mid,2) - mid+1)>0) return solve(bot, mid); 
}

int main(){
    printf("%.10f", solve(0,1));
}
