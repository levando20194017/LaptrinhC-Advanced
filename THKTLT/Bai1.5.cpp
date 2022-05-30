#include<stdio.h>
int counteven(int *arr, int size){
	int count =0;
	for(int i=0;i<size;i++)
		if(arr[i]%2==0) count++;
		return count;
	}
double *maximum(double *a, int size){
	double *max;
	max=a;
	if(a==NULL) return NULL;
	for(int i=0;i<size;i++){
		if(*(max+i)>*max) *max=*(max+i);
		}
	return max;
	}
int main(){
	double a[]={1,5,3,8,9};
	printf("%f", *maximum(a,5));
	return 0;
	}
