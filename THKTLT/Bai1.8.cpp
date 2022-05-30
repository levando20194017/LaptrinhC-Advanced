#include <stdio.h>
#include<stdlib.h>
void allocate_mem(int ***mt, int m, int n){
            int **arr=(int**)malloc(m*sizeof(int*));
            for(int i=0; i<m;i++){
            	*(arr+i)=(int*)malloc(n*sizeof(int));
			}
			*mt=arr;
}
void input(int **mt, int m, int n){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			scanf("%d ",&mt[i][j]);
		}
	}
}
void output(int **mt, int m, int n){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("mt[%d][%d] = ",i,j);
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("%d ",mt[i][j]);
		}
		printf("\n");
	}
}
void free_mem(int **mt, int m, int n){
	for(int i=0;i<m;i++) delete[] mt[i];
	delete[] mt;
}
int main(){ 
int m, n, **mt;
printf("Enter m, n = ");
scanf("%d %d", &m, &n);
allocate_mem(&mt, m, n);
input(mt, m, n);
output(mt, m, n);
	int tong=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(*(*(mt+i)+j)%2==0) tong+=*(*(mt+i)+j);}}
printf("The sum of all even elements is %d", tong);
free_mem(mt, m, n);
return 0;}
