#include<stdio.h>
int UCLN(int a, int b){
	while(a != b){
		if(a>b) a -= b;
		else b -= a;
	}
	return a;
}
int main(){
	printf("Le Van Do 20194017\n");
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d\n%d", UCLN(a, b), UCLN(a, b));
	return 0;
}
