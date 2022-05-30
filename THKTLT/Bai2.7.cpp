#include <iostream>
using namespace std;
template <typename T>
T arr_sum(T a[], int c, T b[], int d){
	T count =0;
	for(int i=0;i<c; i++){
		count+=a[i];
	}
	for(int i=0;i<d;i++){
		count+=b[i];
	}
	return count;
}
int main() {
	printf("Le Van Do 20194017");
    int val;
    cin >> val;
    
    {
        int a[] = {3, 2, 0, val};
        int b[] = {5, 6, 1, 2, 7};
        cout << arr_sum(a, 4, b, 5) << endl;
    }
    {
        double a[] = {3.0, 2, 0, val * 1.0};
        double b[] = {5, 6.1, 1, 2.3, 7};
        cout << arr_sum(a, 4, b, 5) << endl;
    }

    return 0;
}
