#include <iostream>
using namespace std;

int binom(int n, int k) {
    if (k > n) return 0;
    if(k==n) return 1;
    if (k == 0) return 1;
    return binom(n-1, k) + binom(n-1, k-1);
}

int binom2(int n, int k){
	int C[n][n];
//	if(k==0 || k==n) return 1;
	for(int i=0; i<=n; i++){
		C[i][0]=1;
		C[i][i]=1;
	}
	for(int i=2; i<=n; i++){
		for(int j=i-1; j>0; j--){
			C[i][j]= C[i-1][j-1]+ C[i-1][j];
		}
	}
	return C[n][k];
}

int main() {
    int m;
    cin >> m;
    for (int n = 1; n <= m; ++n){
        for (int k = 0; k <= n; ++k)
            printf("%d ", binom(n, k));
        printf("\n");
    }
    for (int n = 1; n <= m; ++n){
        for (int k = 0; k <= n; ++k)
            printf("%d ", binom2(n, k));
        printf("\n");
    }
    return 0;
}
