#include <iostream>
#include <map>
#include <cassert>
#include <string>
using namespace std;
// Example adapted from Josuttis
int main() {
multimap<string, string> mdict;
mdict.insert(make_pair("car",
"voiture"));
mdict.insert(make_pair("car", "auto"));
mdict.insert(make_pair("car", "wagon"));
mdict.insert(make_pair("hello",
"bonjour"));
mdict.insert(make_pair("apple","pomme"));
cout << "\nPrinting all defs of "<< endl;
for(multimap<string,string>::const_iterator it = mdict.lower_bound("car"); it != mdict.upper_bound("car"); it++){
cout << (*it).first << ": "<< (*it).second << endl;
}
}
