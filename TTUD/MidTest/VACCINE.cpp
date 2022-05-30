#include<iostream>
using namespace std;
int main(){
	int count=0;
//	int V,A,C,I,N,E,O,D;
	for(int V=1; V<=10; V++){
		for(int A=1; A<=10; A++){
			for(int C=1; C<=10; C++){
				for(int I=1; I<=10; I++){
					for(int N=1; N<=10; N++){
						for(int E=1; E<=10; E++){
							for(int O=1; O<=10; O++){
									if(V+A+C+I+N+E+O == 20) count++;
									
								}
							}
						}
					}
				}
			}
		}
	cout<<count;
	return 0;
}
