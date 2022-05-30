#include<iostream>
using namespace std;
int n;
void heapify(int A[], int i, int N)
{
int L = 2*i;
int R = 2*i+1;
int max = i;
if(L <= N && A[L] > A[i])
max = L;
if(R <= N && A[R] > A[max])
max = R;
if(max != i){ 
swap(A[i], A[max]);
heapify(A,max,N);
}
}
void buildHeap(int A[], int N) {
for(int i = N/2; i >= 1; i--)
heapify(A,i,N);
}
void heapSort(int A[], int N) {
// index tu 1 -> N
buildHeap(A,N);
for(int i = N; i > 1; i--) {
swap(A[1], A[i]);
heapify(A, 1, i-1); 
}
}


int main(){
	int arr[n];
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>arr[i];
	}
	heapSort(arr,n-1);
	for(int i=1; i<=n; i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}
