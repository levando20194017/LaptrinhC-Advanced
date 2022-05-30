#include<iostream>
using namespace std;
int main(){
	int count=0;
//	int V,A,C,I,N,E,O,D;
	for(int V=0; V<=9; V++){
		for(int A=1; A<=9; A++){
			for(int C=1; C<=9; C++){
				for(int I=0; I<=9; I++){
					for(int N=0; N<=9; N++){
						for(int E=0; E<=9; E++){
							for(int O=0; O<=9; O++){
								for(int D=0; D<=9; D++){
									if((V*1e6+A*1e5+C*1e4+C*1e3+I*100+N*10+E) - (C*1e6+O*1e5+V*1e4+I*1000+D*100+19)==2681431 
									&& V!=A && A!=C&&C!=I&&I!=N&&N!=E&&E!=O&&O!=D&&V!=D&&V!=C&&V!=I&&V!=N&&V!=E&&V!=O<<V!=D
									&&C!=I&&C!=N&&C!=E&&C!=O&&C!=D
									&&A != C && A != I && A != N && A != E && A != O && A != D
									&&I!=N&&I!=E&&I!=O&&I!=D
									&&N!=E&&N!=O&&N!=D
									&&E!=O&&E!=D
									&&O!=D){
									count++;
									cout<<V<<" "<<A<<" "<<C<<" "<<I<<" "<<N<<" "<<E<<" "<<O<<" "<<D<<endl;
									}
								}
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
