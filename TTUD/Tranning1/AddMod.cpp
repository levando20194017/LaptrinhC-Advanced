#include<bits/stdc++.h>
using namespace std;
int main(){
	const int dividend = pow(10, 9) + 7;
	unsigned long long a, b;
	cin>>a>>b;
	int surplus = ((a % dividend) + (b % dividend)) % dividend;
	cout<<surplus;
	return 0;
}
