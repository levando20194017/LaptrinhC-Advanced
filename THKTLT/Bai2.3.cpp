#include <stdio.h>
using namespace std;
int get_value(int x, int a=2, int b=1, int c=0){
	return a*x*x+b*x+c;
}
int main(){
	printf("Le Van Do 20194017");
    int x;
    scanf("%d", &x);
    
    int a = 2; //# giá tr? m?c d?nh c?a a
    int b = 1; //# giá tr? m?c d?nh c?a b
    int c = 0; //# giá tr? m?c d?nh c?a c
    scanf("%d%d%d", &a,&b,&c);
    printf("a=2, b=1, c=0: %d\n", get_value(x));
    printf("a=%d, b=1, c=0: %d\n", a, get_value(x, a));
    printf("a=%d, b=%d, c=0: %d\n", a, b, get_value(x, a, b));
    printf("a=%d, b=%d, c=%d: %d\n", a, b, c, get_value(x, a, b, c));
    
    return 0;
}
