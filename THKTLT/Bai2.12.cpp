#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main()
{  
    cout << "Le Van Do 20194017\n";
    string st;
    vector<int> keyword;
    vector<int> val;
    while (getline(cin, st))
    {
        if (st == "")
            break;
        int area = st.find(' ');
        stringstream sstr(st);
        string x;
        sstr >> x;
        keyword.push_back(stoi(x));
        sstr >> x;
        val.push_back(stoi(x));
    }
    for (int i = 0; i < keyword.size(); i++)
    {
        for (int j = i; j < keyword.size(); j++)
        {
            if (val.at(i) < val.at(j))
            {
                swap(val.at(i), val.at(j));
                swap(keyword.at(i), keyword.at(j));
            }
            if(val.at(i)==val.at(j) && keyword.at(i)<keyword.at(j)){
                swap(val.at(i), val.at(j));
                swap(keyword.at(i), keyword.at(j));
            }
        }
    }
    for (int i = 0; i < keyword.size(); i++)
    {
        cout << keyword.at(i) << " " << val.at(i) << endl;
    }
    return 0;
}

