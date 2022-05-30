#include<iostream>
using namespace std;
void move(char A, char B, char C, int n){
	if(n==1){
	 printf("%c -> %c\n", A, B);
}
	else{
	move(A, C, B, n-1);
	move(A, B, C, 1);
	move(C, B, A, n-1);
}
}
int main(){
	move('A','B', 'C', 3);
	return 0;
}
