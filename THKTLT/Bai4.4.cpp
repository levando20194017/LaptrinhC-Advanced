#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void print_vector(const vector<int> &a) {
    for (int v : a) cout << v << ' ';
    cout << endl;
}

void delete_even(vector<int> &a) {
   for(int i=0; i < a.size(); i++){
   	if(a.at(i)%2==0){
	 a.erase(a.begin()+i , a.begin()+i+1);
	i--;
	}
   }
}

void sort_decrease(vector<int> &a) {
	int *b = new int[a.size()];
	int i=0;
    for(int v: a){
    	b[i]=v;
    	i++;
	}
	int swap;
	do{
		swap = 0;
		for(int i=0; i< a.size(); i++){
			for(int j=i+1; j<a.size(); j++){
				if(b[j] > b[i]){
					swap = 1;
					int t= b[j];
					b[j] = b[i];
					b[i] = t;
				}
			}
		}
	}while(swap==1);
	int c= a.size();
	a.erase(a.begin(), a.end());
	for(int i=0; i< c; i++){
		a.push_back(b[i]);
	}
}

vector<int> merge_vectors(const vector<int> &a, const vector<int> &b) {
   vector<int> c;
   int i= 0;
   int j= 0;
    while(i< a.size() && j<b.size()){
    	if(a.at(i) > b.at(j)){
    		c.push_back(a.at(i));
    		i++;
		}
		else{
			c.push_back(b.at(j));
			j++;
		}
	}
	while(i< a.size()){
		c.push_back(a.at(i));
		i++;
	}
	while(j< b.size()){
		c.push_back(b.at(j));
		j++;
	}
   return c;
}

int main() {
	cout<<"Le Van Do 20194017\n";
    int m, n, u;
    std::vector<int> a, b;
    
    std::cin >> m >> n;
    for(int i = 0; i < m; i++){
        std:: cin >> u;
        a.push_back(u);
    }
    for(int i = 0; i < n; i++){
        std:: cin >> u;
        b.push_back(u);
    }

    delete_even(a);
    cout << "Odd elements of a: ";
    print_vector(a);

    delete_even(b);
    cout << "Odd elements of b: ";
    print_vector(b);

    sort_decrease(a);
    cout << "Decreasingly sorted a: ";
    print_vector(a);

    sort_decrease(b);
    cout << "Decreasingly sorted b: ";
    print_vector(b);

    vector<int> c = merge_vectors(a, b);
    cout << "Decreasingly sorted c: ";
    print_vector(c);

    return 0;
}
