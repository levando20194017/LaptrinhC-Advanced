#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<math.h>
using namespace std;
struct complex{
	double real;
	double imag;
};
complex operator +(complex a, complex b){
	complex c;
	c.real= a.real+ b.real;
	c.imag= a.imag+ b.imag;
	return c;
}
complex operator -(complex a, complex b){
	complex c;
	c.real= a.real- b.real;
	c.imag= a.imag- b.imag;
	return c;
}
complex operator *(complex a, complex b){
	complex c;
	c.real= a.real*b.real-a.imag*b.imag;
	c.imag=a.real*b.imag+a.imag*b.real;
	return c;
}
complex operator / (complex a, complex b){
	complex c;
	c.real = (b.real * a.real + b.imag * a.imag) / (b.real * b.real + b.imag * b.imag);
    c.imag = (b.real * a.imag - b.imag*a.real)/ (b.real * b.real + b.imag * b.imag);
	return c;
}
ostream& operator << (ostream& out, const complex &a) {
    out << '(' << std::setprecision(2) << a.real << (a.imag >= 0 ? '+' : '-') << std::setprecision(2) << fabs(a.imag) << 'i' << ')';
    return out;
}
int main() {
	cout<<"Le Van Do 20194017";
    double real_a, real_b, img_a, img_b;
    cin >> real_a >> img_a;
    cin >> real_b >> img_b;
    
    complex a{real_a, img_a};
    complex b{real_b, img_b};
    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " * " << b << " = " << a * b << endl;
    cout << a << " / " << b << " = " << a / b << endl;
    
    return 0;
}
