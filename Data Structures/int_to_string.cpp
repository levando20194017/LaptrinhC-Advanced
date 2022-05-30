#include<stdio.h>
#include<stdlib.h>
int main(){
		int a,b;
		char buffer[33];
		scanf("%d%d", &a, &b);
		int s= a+b;
		itoa(s, buffer, 2);
		printf("%s", buffer);
	return 0;
	}
