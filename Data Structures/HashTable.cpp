#include<iostream>
#define HashTableSize 27
using namespace std;
string HashTable[HashTableSize];
int hashFunction(string s){
	return (s[0]-'a');
	}
void insert(string s){
	int index=hashFunction(s);
	int k=1;
	while(HashTable[index]!= ""){
		index=(index+k*k)%HashTableSize;
		k++;
		}
		HashTable[index]=s;
	}
int search(string s){
		int index=hashFunction(s);
		int k=1;
	while(HashTable[index]!= ""&&HashTable[index]!= s){
		index=(index+k*k)%HashTableSize;
		k++;
		}
	if	(HashTable[index]==s) return index;
	else  return -1;
	}
int main(){
	insert("coconut");
	insert("banana");
	insert("grapes");
	insert("cherry");
	insert("apple");
	insert("mango");
	insert("kiwi");
	insert("trawberry");
	insert("melon");
	cout<<"index of "<<"coconut is "<<search("coconut")<<endl;
	cout<<"index of "<<"kiwi is "<<search("kiwi")<<endl;
	cout<<"index of "<<"grapes is "<<search("grapes")<<endl;
	cout<<"index of "<<"banana is "<<search("banana")<<endl;
	cout<<"index of "<<"mango is "<<search("mango")<<endl;
	cout<<"index of "<<"apple is "<<search("apple")<<endl;
	cout<<"index of "<<"cherry is "<<search("cherry")<<endl;
	cout<<"index of "<<"cherry is "<<search("cherry")<<endl;
	cout<<"index of "<<"strawberry is "<<search("strawberry")<<endl;
	cout<<"index of "<<"melon is "<<search("melon");
	return 0;
	}
