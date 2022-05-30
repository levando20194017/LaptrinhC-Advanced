#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    
	cout << "Le Van Do 20194017\n";
    int val1, val2;
    cin >> val1 >> val2;
    vector< vector<int> > a = {
        {1, 3, 7},
        {2, 3, 4, val1},
        {9, 8, 15},
        {10, val2},
    };

    int n = a.size();
    int arr[1000];
    vector <int> b;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        arr[i] = 0;
        for (unsigned int j = 0; j < a[i].size(); j++)
            arr[i] += a[i][j];
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                a[j].swap(a[i]);
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }

    for (const auto& v : a) {
        for (int it : v) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}
