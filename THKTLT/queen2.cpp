#include <bits/stdc++.h>
using namespace std;
const int NMAX = 20;
int a[NMAX], n;
void print_sol(){
    for(int i = 1; i <= n; i++)
        cout << a[i] << (i == n ? '\n' : ' ');
}
bool isCandidate(int j, int k){
    for(int i = 1; i < k; i++)
        if ((j == a[i]) || (fabs(j - a[i]) == (k - i)))
            return false;
    return true;
}
void TRY(int k){
    for(int j = 1; j <= n; j++){
        if (isCandidate(j, k)){
            a[k] = j;
            if (k == n) print_sol();
            else TRY(k + 1);
        }
    }
}
int main(){
    n = 4;
    TRY(1);
    return 0;
}

