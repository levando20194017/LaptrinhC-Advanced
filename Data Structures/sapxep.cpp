#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void insert(int a[]){
	for(int i=1;i<10;i++){
	int n=i;
	while(n>0){
	if(a[n]<a[n-1]){
		int p=a[n];
		a[n]=a[n-1];
		a[n-1]=p;
		}
		n--;
		}
	}
	}
void insertionSort(int A[], int N)
{
// index tu 1 -> N
for(int k = 1; k < N; k++){
int last = A[k];
int j = k;
while(j > 0 && A[j-1] >
last){
A[j] = A[j-1];
j--;
}
A[j] = last;
}
}
void luachon(int a[]){
	int k,n;
	for(int m=0;m<=8;m++){
		int min=a[m];
		int min1=a[m+1];
		for(int i=m+1;i<10;i++){
			if(a[i]<min1){ min1=a[i];
			}
			}
	for(int i=m+1;i<10;i++){
		if(min1>min){ k=m;}
		else
		if(a[i]<min){
		 min=a[i];
	      k=i;
		}
		}
		a[k]=a[m];
		a[m]=min;
	}
	}
void selectionsort(int a[], int n){
	for(int i=0;i<10;i++){
		int min=i;
		for(int j=i+1;j<10;j++){
			if(a[min]>a[j]) min=j;
		}
		int tmp=a[i];
		a[i]=a[min];
		a[min]=tmp;
	}
}
void quicksort(int a[], int L, int N){
if(N!=L){
	int count=0;
	for(int i=L+1;i<N;i++){
		if(a[i]<a[L]) count++;
		}
		int tmp= a[L+count];
		a[L+count]=a[L];
		a[L]=tmp;
		int j=0;
			for(int i=L;i<N;i++){
				if(a[i]<a[L+count]){ 
				int h=a[i];
				a[i]=a[j];
				a[j]=h;
				j++;
				}
				}	
			quicksort(a,L,L+count);
			quicksort(a,L+count+1,N);
			}
			}
//void quickSort(int A[], int L, int R) {
//if(L < R){
//int index= (L + R)/2;
//index = partition(A, L, R, index);
//if(L < index)
//quickSort(A, L, index-1);
//if(index < R)
//quickSort(A, index+1, R);
//}
//}
//int partition(int A[], int L, int R, int indexPivot) {
// int pivot = A[indexPivot];
//swap(A[indexPivot], A[R]);
//int storeIndex = L;
//for(int i = L; i <= R-1; i++){
// if(A[i] < pivot){
// swap(A[storeIndex], A[i]);
// storeIndex++;
// }
// }
//swap(A[storeIndex], A[R]);
//return storeIndex;
//}
//The dã g?i Hôm nay lúc 00:05
void swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

void bubleSort(int A[], int N) {
// index tu 1 den N
int swapped;
do{
swapped = 0;
for(int i = 0; i < N-1; i++){
if(A[i] > A[i+1]){
int tmp = A[i];
A[i] = A[i+1];
A[i+1] = tmp;
swapped = 1;
}
}
}while(swapped == 1);
}
int main(){
	srand(time(NULL));
	int *a;
	a= (int*)malloc(100*sizeof(int));
	for(int i=0;i<100;i++){
		a[i]= rand()%500;
	}	
//	insert(a);
//	insertionSort(a,100000);
//luachon(a);
//selectionsort(a,100000);
quicksort(a,0,100);
	for(int i=0;i<100;i++){
		printf("%3d ", a[i]);
		}
		return 0;
		free(a);
	}
