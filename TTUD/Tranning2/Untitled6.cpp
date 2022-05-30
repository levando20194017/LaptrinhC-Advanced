#include <iostream>
using namespace std;
const int MAX = 100;
int x[MAX];
int N,K;
long long S;
long long  sum;
long long cr[MAX];
int dem;
int check(int v, int k1){
    if(k1 < K) return 1;
    return sum+v == S;
}
void TRY(int k1){
    for(int v = x[k1-1] +1 ; v <= N ; v++){
        if(check(cr[v],k1)){
            //printf("TRY(%d), v = %d, sum = %d\n",k,v,sum);
            x[k1] = v;
            sum += cr[v]; // update incrementally
            if(k1 == K) dem++;
            else TRY(k1+1);
            sum -= cr[v]; // recover when backtracking
        }
    }
}
int main(){
	cin>>N>>K>>S;
    for(int i = 1; i<=N ;i++) cin>>cr[i];
    x[0] = 0;
    dem = 0;
    sum = 0;
    TRY(1);
    cout<<dem<<endl;
}
