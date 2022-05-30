#include <iostream>
#include <string>
using namespace std;
struct bignumber
{
    char sign;
    string number;
};
bignumber operator+(bignumber firstBignumber, bignumber secondBignumber)
{
    string a = firstBignumber.number;
    string b = secondBignumber.number;
    while (a.length() < b.length())
        a = "0" + a;
    while (b.length() < a.length())
        b = "0" + b;

    int nho = 0;
    string rs = "";
    char dau;
    if (firstBignumber.sign == secondBignumber.sign)
    {
        for (int i = a.length() - 1; i >= 0; i--)
        {
            int tmp = (int)(a[i]) - 48 + (int)(b[i]) - 48 + nho;
            nho = tmp / 10;
            tmp = tmp % 10;
            rs = (char)(tmp + 48) + rs;
        }
        if (nho > 0)
            rs = "1" + rs;
        dau = firstBignumber.sign;
    }
    else
    {
        for (int i = a.length() - 1; i >= 0; i--)
        {
            int tmp = a[i] - b[i] - nho;
            if (tmp < 0)
            {
                tmp += 10;
                nho = 1;
            }
            else
                nho = 0;
            rs = (char)(tmp % 10 + 48) + rs;
        }
        while (rs.length() > 1 && rs[0] == '0')
            rs.erase(0, 1);
        if (a > b)
        {
            dau = secondBignumber.sign;
        }
        else
        {
            dau = firstBignumber.sign;
        }
    }

    bignumber c{dau, rs};

    return c;
}
bignumber operator-(bignumber firstBignumber, bignumber secondBignumber)
{
    string a = firstBignumber.number;
    string b = secondBignumber.number;
    while (a.length() < b.length())
        a = "0" + a;
    while (b.length() < a.length())
        b = "0" + b;
    int nho = 0;
    string rs = "";
    char dau;
    bool kt = false;
    if (a < b)
    {
        swap(a, b);
        kt =true;
    }

    if (firstBignumber.sign != secondBignumber.sign)
    {
        rs = (firstBignumber + secondBignumber).number;
        dau = firstBignumber.sign;
    }
    else
    {
        for (int i = a.length() - 1; i >= 0; i--)
        {
            int tmp = a[i] - b[i] - nho;
            if (tmp < 0)
            {
                tmp += 10;
                nho = 1;
            }
            else
                nho = 0;
            rs = (char)(tmp % 10 + 48) + rs;
        }
        while (rs.length() > 1 && rs[0] == '0')
            rs.erase(0, 1);
        if (kt==false)
        {
            dau = firstBignumber.sign;
        }
        else
        {
           if(firstBignumber.sign =='0' ) dau ='1';
           else dau ='0';
        }
    }
    if( a == b) dau ='1';

    bignumber c{dau, rs};

    return c;
}
bignumber operator*(bignumber firstBignumber, bignumber secondBignumber)
{
    string a = firstBignumber.number;
    string b = secondBignumber.number;
    string rs = "";
    char dau;
    int n = a.length();
    int m = b.length();
    int len = n + m - 1;
    int carry = 0;
    for (int i = len; i >= 0; i--)
    {
        int tmp = 0;
        for (int j = n - 1; j >= 0; j--)
            if (i - j <= m && i - j >= 1)
            {
                int a1 = a[j] - 48;
                int b1 = b[i - j - 1] - 48;
                tmp += a1 * b1;
            }
        tmp += carry;
        carry = tmp / 10;
        rs = (char)(tmp % 10 + 48) + rs;
    }
    while (rs.length() > 1 && rs[0] == '0')
        rs.erase(0, 1);
    if (firstBignumber.sign == secondBignumber.sign)
        dau = '1';
    else
        dau = '0';
    bignumber c{dau, rs};

    return c;
}

int main()
{
    cout << "Le Van Do 20194017";
    char dau;
    string s;
    cin >> dau;
    getline(cin, s);
    bignumber a{dau, s};
    cin >> dau;
    getline(cin, s);
    bignumber b{dau, s};

    bignumber c= a*b;
    bignumber d = a+a+a;
    bignumber e = b+b+b+b;
    bignumber f= c-d;
    cout<<(f-e).sign<<(f-e).number;
    return 0;
}
