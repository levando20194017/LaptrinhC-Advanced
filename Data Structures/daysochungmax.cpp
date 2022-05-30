#include<stdio.h>
int count =0;
int j=0;
int maxcount(int k, int a[], int b[]){
	for(int i=j; i<11;i++){
		if(a[k]==b[i]){
		count ++;
		j=i+1;
		break;
	}
	}
	if(k==8)
	return count;
	else maxcount(k+1, a, b);
}
int main(){
	int max=0;
	int x[]={0,3,7,2,5,1,4,9};
	int y[]={0,4,3,2,3,6,1,5,4,9,7};
//	for(int i=0;i<5;i++){
//	int max1= maxcount(i,x,y);
//	max=max1>max?max1:max;
//	}
	printf("%d", maxcount(0,x,y));
	return 0;
}
