#include<stdio.h>
int maxL(int *a, int i, int j){
	int s=0;
int max=-99999;
	for(int k=j;k>=i;k++){
		s=s+a[k];
		max=max>s?max:s;
		}
		return max;
	}
int maxR(int *a, int i, int j){
	int s=0;
	int max=-99999;
	for(int k=i+1;k<j;k++){
		s=s+a[k];
		max=max>s?max:s;	
		}
		return max;
	}
//int MAX(int wL, int wR, int wD){
//	int max1=wL>wR?wL:wR;
//	int max2=max1>wD?max1:wD; 
//	return max2;
//	}
int maxSub(int *a, int &i, int &j){
	if(i==j)
	return a[i];
	else{
	int m=(i+j)/2;
	int wL=maxSub(a, i, m);
	int wR=maxSub(a, m, j);
	int wD= maxL(a,i,m) + maxR(a,m,j);
	int max1=wL>wR?wL:wR;
	int max2=max1>wD?max1:wD; 
	return max2;
	}
}
int main(){
	int i=0; int j=10;
int a[]={1,4,8,4,2,-23,-26,9,7,-24};
printf("%5d",maxSub(a,&i,&j));
	return 0;
}
