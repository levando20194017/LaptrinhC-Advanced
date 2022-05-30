#include<iostream>
using namespace std;
int main(){
	int count;
	int x1, x2, x3, x4, x5;
	for(int x5=1; x5<=10; x5++){
		for(int x4=1; x4<=12; x4++){
			for(int x3=1; x3<=16; x3++){
				for(int x2=1; x2<=23; x2++){
					for(int x1=1; x1<=46; x1++){
						if(x1+2*x2+3*x3+4*x4+5*x5 == 60 && x4 + x5 ==x1 && x1+x3<x2){
							count++;
						}
					}
				}
			}
		}
	}
	cout<<count;
	return 0;
}
