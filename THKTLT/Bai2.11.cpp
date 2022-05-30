#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{  
  cout<<"Le Van Do 20194017\n";
  int x, y;
  cin >> x;
  int *a = (int*)malloc((x+1)*sizeof(int));
  for (int i = 0; i <= x; i++)
  {
    cin >> a[i];
  }
  cin >> y;
  int *b = (int*)malloc((y+1)*sizeof(int));
  for (int i = 0; i <= y; i++)
  {
    cin >> b[i];
  }

  int *c = (int*)calloc(x+y+1, sizeof(int));
  for (int i = 0; i <= x; i++)
  {
    for (int j = 0; j <= y; j++)
    {
      c[i+j] += a[i]*b[j];
    }
  }
  int _xor = c[0];
  for (int i = 1; i <= x + y; i++)
  {
    _xor = _xor ^ c[i];
  }
  cout << _xor;
}
