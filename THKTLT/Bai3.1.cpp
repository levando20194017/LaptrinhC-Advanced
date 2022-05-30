#include<stdio.h>
int Lucas(int n){
	if(n==0) return 2;
	if(n==1) return 1;
	return Lucas(n-1)+ Lucas(n-2);
}
int main(){
	printf("Le Van Do 20194017\n");
	printf("%d", Lucas(5));
	return 0;
}
