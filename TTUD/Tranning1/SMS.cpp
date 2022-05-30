#include<iostream>
#include<vector> 
using namespace std;
int main(){
	int n;
	cin>>n;
	int cas[n];
	for(int i=1; i<=n; i++){
		cas[i] = 0;
	}
	cin.ignore(); 
	string s;
	vector<string> arr = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz", " "};
	for(int i=1; i<=n; i++){
		getline(std::cin, s);
		for(int k=0; k<s.length(); k++){
			for(string alphabet : arr){
				for(int j=0; j<alphabet.length(); j++){
				if(s[k] == alphabet[j])
				cas[i] += j + 1;
				}
			}
		}
	}
	for(int i=1; i<=n; i++){
		cout<<"case #"<<i<<": "<<cas[i]<<endl;
	}
return 0; 
}
