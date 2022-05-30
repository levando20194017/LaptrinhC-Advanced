#include<iostream>
#include<ostream>
using namespace std;

struct bigNum
{
    /* data */
    string num = "";
};

void intitialize_2_bigNums(bigNum& a, bigNum& b);

void standardized_string_length(bigNum& a, bigNum& b);

bigNum operator + (bigNum a, bigNum b);

ostream& operator << (ostream& out, const bigNum& a);

int main()
{
    bigNum a, b;
    intitialize_2_bigNums(a, b);
    standardized_string_length(a, b);
    cout << a + b;
    return 0;
}

void intitialize_2_bigNums(bigNum& a, bigNum& b) {
    cin >> a.num >> b.num;
}

void standardized_string_length(bigNum& a, bigNum& b) {
    int lengthOfA = a.num.length();
    int lengthOfB = b.num.length();
    if (lengthOfA > lengthOfB)
    {
        int lengthOfZero = lengthOfA - lengthOfB;
        string zeroSeq = "";
        for (int i = 0; i < lengthOfZero; i++)
            zeroSeq += '0';
        b.num = zeroSeq + b.num;
    }
    else
    {
        int lengthOfZero = lengthOfB - lengthOfA;
        string zeroSeq = "";
        for (int i = 0; i < lengthOfZero; i++)
            zeroSeq += '0';
        a.num = zeroSeq + a.num;
    }
}

bigNum operator + (bigNum a, bigNum b) {
    bigNum c;
    string result = "";
    int surplus = 0;
    int total = 0;      // save result of (int + int)
    while (!a.num.empty())
    {
        total = a.num.back() - '0' + b.num.back() - '0' + surplus;
        surplus = total / 10;
        result = to_string(total % 10) + result;
        a.num.pop_back();
        b.num.pop_back();
    }
    if (surplus)
        result = '1' + result;
    c.num = result;
    return c;
}
ostream& operator << (ostream& out, const bigNum& a)
{
	out << a.num << endl;
	return out;
}
