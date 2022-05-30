#include<iostream>
using namespace std;
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	pair<int , int> d;
	d = make_pair(0,0);
	int count = 0;
	while(true){
			d.first = a;	count++;
			if(d.first == c) break;
			if(d.second + d.first <=b){
			int n = b/a;
			count += n;
			d.second = n*a;
			d.first = 0;
			}else{
				d.first = d.first - (b-d.second);	count ++;
				d.second = b;
				if(d.first == c) break;
				else{
					d.second = 0; count++;
					d.second = d.first; count++;
					d.first = 0;
				}
			}
			if(d.first == 0 && d.second == 0){
				cout<<-1;
				return 0;
			}
		}
	cout<<count;
	return 0;
}
