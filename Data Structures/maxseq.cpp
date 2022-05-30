#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000
int a[MAX];
int n;

void input(char* fn){
    FILE* f = fopen(fn,"r");// mo file de doc du lieu
    fscanf(f,"%d",&n);// doc gia tri n
    for(int i = 1; i<= n; i++){
        fscanf(f,"%d",&a[i]);
    }
    fclose(f);

    //printf("%d: ",n);
    //for(int i = 1; i <= n; i++)
    //    printf("%d ",a[i]);
}
void genData(char* fn,int n){
    srand(time(NULL));

    FILE* f = fopen(fn,"w");
    fprintf(f,"%d\n",n);
    for(int  i = 1 ; i <= n; i++){
        int x = 500-rand()%1000;
        fprintf(f,"%d ",x);
    }
    fclose(f);
}
void algo1(){
    int rs = -10000000;
    for(int i = 1; i<= n; i++){
        for(int j = i; j <= n; j++){
            int T = 0;
            for(int k = i; k <= j; k++){
                T += a[k];
            }
            if(T > rs) rs = T;
        }
    }
    printf("rs = %d\n",rs);
}
void algo2(){
    int rs = -100000000;
    for(int i = 1; i <= n; i++){
        int T = 0;
        for(int j = i; j <= n; j++){
            T += a[j];
            rs = T > rs ? T : rs;
        }
        //if(i % 1000 == 0)
        //    printf("i = %d, T = %d, rs = %d\n",i,T,rs);
    }
    printf("algo2, rs = %d\n",rs);
}
void algo4(){
    int rs = -1000000;
    int S = a[1];
    for(int i = 2; i <= n; i++){
        if (S > 0){
            S = S + a[i];
        }else{
            S = a[i];
        }
        rs = S > rs ? S: rs;
    }
    printf("algo4, rs = %d\n",rs);
}
int main(){

    //input("seq-8.txt");
    char* filename = "seq-100000.txt";
    //char* filename = "seq-8.txt";
    //genData(filename,1000);
    input(filename);
    algo4();
}
