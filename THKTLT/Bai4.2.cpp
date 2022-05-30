 #include <iostream>
 #include <cmath>
 #include <iomanip>
 #include <utility>
 using namespace std;
 using Point = pair<double, double>;

double area(Point a, Point b, Point c) {
		return ((double) 1/2*abs((b.first - a.first)*(c.second - a.second)-(c.first - a.first)*(b.second - a.second)));
}

 int main() {
 	cout<<"Le Van Do 20194017\n";
     cout << setprecision(2) << fixed;
     cout << area({1, 2}, {2.5, 10}, {15, -5.25}) << endl;
     return 0;
 }
