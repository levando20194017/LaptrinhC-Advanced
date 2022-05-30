#include<bits/stdc++.h>
using namespace std;
const int N = 4;
const int INF = 10000000;
int C[N][N];
int iMem[N][1<<N];
int S;
void generate_instance(){
for(int i = 0; i < N-1; i++){
for(int j = i+1; j < N; j++){
int rand_val = rand()%100;
C[i][j] = rand_val;
C[j][i] = rand_val;
cout << i << " " << j << " : " << C[i][j] << endl;
}
}
}
int TSP(int i, int S){
cout << "calling " << i << ", " << S << endl;
if(S == ((1<<N))-1){
cout << " return 1" << endl;
return C[i][0];
}
if(iMem[i][S] != -1) return iMem[i][S];
int res = INF;
for(int j = 0; j < N; j++){
if(S & (1<<j))
continue;
res = min(res, C[i][j] + TSP(j , S | (1 << j)));
}
iMem[i][S] = res;
return res;
}
void Trace(int i, int S){
cout << i << " ";
if(S ==((i << N)) - 1) return;
int res = iMem[i][S];
for(int j = 0; j < N; j++){
if(S & (1 << j))
continue;
if(res == C[i][j] + iMem[j][S | (1 << j)]){
Trace(j, S | (1 << j));
break;
}
}
}
int main(){
generate_instance();
memset(iMem, -1, sizeof(iMem));
TSP(0, 1<<0);
cout << iMem[0][1 << 0] << endl;
Trace(0, 1<<0);
}
