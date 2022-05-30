#include<stdio.h>
using namespace std;

int main(){
	// mênh dê bat giu
	int m=0;
	int n=0;
	auto t= [&, n](int a){
		m=n+a; // nêu không có mutable thì thì biên n bên trong không dduoc phep thay dôi
	};
	auto f= [&, n](int a) mutable{
		m= ++n +a; // nêu có mutable thì biên n bên trong duoc thay dôi nhung gia tri ben ngoai van giu nguyen
	};
	f(4);
	printf("%d", m);
	return 0;
}
