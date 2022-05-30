#include<stdio.h>
#include<stdlib.h>
void reversearray(int arr[], int size){

    int l = 0, r = size - 1, tmp;
    for(int i=0;i<=r/2;i++){
    	tmp= arr[i];
    	arr[i]=arr[r-i];
    	arr[r-i]=tmp;
		}
}
void ptr_reversearray(int *arr, int size){
	int *ptr=(int *)malloc(size*sizeof(int));
	ptr=arr;
    int l = 0, r = size - 1, tmp;
    for(int i=0;i<=r/2;i++){
    	tmp= *ptr[i];
    	*ptr[i]=*ptr[r-i];
    	*ptr[r-i]=tmp;
		}
		free(ptr);
}
int main(){
	int arr[] = {4, -1, 5, 9};
ptr_reversearray(arr,4);
for(int i=0;i<4;i++){
	printf("%d ", arr[i]);
	}
	return 0;
	}

