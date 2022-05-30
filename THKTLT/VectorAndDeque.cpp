#include<iostream>
#include <vector>
#include <deque>
using namespace std;
int main(int argc, char* argv[]) {
//cout << "With a vector:" << endl;
//vector<int> v;
//v.push_back(4); v.push_back(3);
//v.push_back(37); v.push_back(15);
//int* p = &v.back();
//cout << *p << " " << v.at(3) << " " //must be same
//<< p << " " << &v.at(3) << endl; //must be same
//v.push_back(99);
//cout << *p << " " << v.at(3) << " " //may be different*
//<< p << " "<<&v.at(3) << endl; //probably different
 //Deque Implementation
cout << "With a deque:" << endl;
deque<int> d;
d.push_back(4); d.push_back(3);
d.push_back(37); d.push_back(15);
int* p = &d.back();
cout << *p << " " << d.at(3) << " " //must be same
<< p << " " << &d.at(3) << endl; //must be same
d.resize(32767); //probably causes realloc
cout << *p << " " << d.at(3) << " " //must be same
<< p << " " << &d.at(3) << endl; //must be same
}
