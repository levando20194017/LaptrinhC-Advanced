#include<iostream>
#include<stack>
using namespace std;
int main(){
	unsigned long long int a, b;
	cin>>a>>b;
	stack <int> s;
	int a1 = a%10;
	int b1 = b%10;
	a = a/10;
	b = b/10;	
	int c = a1 + b1;	
	s.push(c%10);	
	int d = c/10;	
	while(a>0 || b>0){
		a1 = a%10;
		b1 = b%10;
		a = a/10;
		b = b/10;
		c = a1 + b1 + d;
		s.push(c%10);
		d = c/10;
	}
	if(d>0) s.push(d);
	while(!s.empty()){
		cout << s.top();
		s.pop();
	}
	return 0;
}
