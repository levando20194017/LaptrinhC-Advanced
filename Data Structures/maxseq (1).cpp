#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000
void algo4(int a[], int n){
    int rs = -1000000;
    int S = a[0];
    for(int i = 1; i < n; i++){
        if (S > 0){
            S = S + a[i];
        }else{
            S = a[i];
        }
        rs = S > rs ? S: rs;
    }
    printf("algo4, rs = %d\n",rs);
}
void algo1(int a[], int n){
    int rs = -10000000;
    for(int i = 0; i< n; i++){
        for(int j = i; j < n; j++){
            int T = 0;
            for(int k = i; k <= j; k++){
                T += a[k];
            }
            if(T > rs) rs = T;
        }
    }
    printf("rs = %d\n",rs);
}
int main(){
	int n;
	scanf("%d",&n);
int a[]={2, 4, -7, 5, 7, -10, 4, 3};
    //input("seq-8.txt");
//    char* filename = "seq-100000.txt";
    //char* filename = "seq-8.txt";
    //genData(filename,1000);
//    input(filename);
    algo4(a, n);
}
