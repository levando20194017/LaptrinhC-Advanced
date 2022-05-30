#include<iostream>
#include<string.h>

using namespace std;

struct bigNum{
	char sign;
	char num[101];
};
int main(){
	char a[102],b[102];
	fgets(a,sizeof(a),stdin);
	fgets(b,sizeof(b),stdin);
	bigNum biga,bigb;
	biga.sign = a[0];
	bigb.sign = b[0];
	strcpy(biga.num, a + 1);
	strcpy(bigb.num,b+1);
}
