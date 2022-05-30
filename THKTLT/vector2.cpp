#include<iostream>
#include<vector>
using namespace std;
int main(){
vector<int> vect;
for(int i = 1; i <= 5; i++)
vect.push_back(i);
for(int i = 0; i < vect.size(); i++)
cout << vect[i] << ' ';
for(auto &u : vect)
cout << u << ' '; 
}
