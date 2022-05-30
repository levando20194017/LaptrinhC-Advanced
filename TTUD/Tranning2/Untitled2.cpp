#include<iostream>
#include<string.h>
using namespace std;

int N;
int count = 0;
string a;

bool isPalindrome(const string& s) {
if (s.length() < 2) {
return true;
} else {
if (s[0] != s[s.length() - 1]) {
return false;
}
string middle = s.substr(1, s.length() - 2);
return isPalindrome(middle);
}
}
void Test(){
	for(int i=0; i<N-1; i++){
		for(int j=i+1; j<N; j++){
			string ss = "";
			for(int k = i; k<=j; k++)
				ss += a[k];
			if(isPalindrome(ss)) count++;
		}
	}
}
int main(){
	cin>>N;
	cin>>a;
	Test();
	cout<<count;
}
