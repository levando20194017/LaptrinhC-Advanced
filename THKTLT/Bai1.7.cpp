#include <stdio.h>
#include<stdlib.h>
int n, tmp;
int *a;
int main(){
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    a=(int*)malloc(n*sizeof(int));
    for(int i = 0; i < n; i++)
        scanf("%d", a+i);
    printf("The input array is: \n");
    for(int i = 0; i < n; i++)
        printf("%d ", *(a + i));
    printf("\n");
    int swap;
    do{
    	swap=0;
    	for(int i=0;i<n-1;i++){
    		for(int j=0;j<n-1;j++){
    			if(*(a+i+1)<*(a+i)){
    				swap=1;
    				tmp=a[i+1];
    				a[i+1]=a[i];
    				a[i]=tmp;
				}
				}
	}
	}while(swap==1);
    	
    printf("The sorted array is: \n");
    for(int i = 0; i < n; i++)
        printf("%d ", *(a + i));
    printf("\n");
    
    delete [] a;
    return 0;
}
