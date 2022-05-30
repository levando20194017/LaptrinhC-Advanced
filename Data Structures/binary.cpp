#include <iostream>
#include <bitset>
#include<string>
int main()
{
	std::string a="1110";
	std::string b="1011";
    unsigned long decimal1 = std::bitset<8>(a).to_ulong(); unsigned long decimal2= std::bitset<8>(b).to_ulong();
    unsigned long decimal = decimal1+ decimal2;
    std::string binary = std::bitset<8>(decimal).to_string();
    std::cout<<binary;
	std::cout<<"\n"<<decimal;
    return 0;
}
