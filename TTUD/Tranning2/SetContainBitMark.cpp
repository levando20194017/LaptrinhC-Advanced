#include<iostream>
#include<vector>
using namespace std;
int main(){
	int elementsOfA, elementsOfB;
	//int A[elementsOfA], B[elementsOfB];
	vector<int> A, B;
	int a,b;
	int count = 0;
	cin>>elementsOfA;
	for(int i=0; i<elementsOfA; i++){
		cin>>a;
		A.push_back(a);
	}
	cin>>elementsOfB;
	for(int i=0; i<elementsOfB; i++){
		cin>>b;
		B.push_back(b);
	}
	if(elementsOfA < elementsOfB) cout<<false;
	else{
		for(int i=0; i<elementsOfB; i++){
			for(int j=0; j<A.size(); j++){
				
				if(B[i] == A[j]){
					count ++;
					A.erase(A.begin() + j);
					break;
				}
			}
		}
		if(count == elementsOfB) cout<<true;
		else cout << false;
	}
	return 0;
}
