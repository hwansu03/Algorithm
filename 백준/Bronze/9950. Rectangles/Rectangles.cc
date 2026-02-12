#include <iostream>
using namespace std;

int main() {
  int a, b, c;
  while (cin >> a >> b >> c) {
    if (a == 0 && b == 0 && c == 0)
      break;

    if (a == 0) {
      cout << c / b << " " << b << " " << c << endl;
    }
    if (b == 0) {
      cout << a << " " << c / a << " " << c << endl;
    }
    if (c == 0) {
      cout << a << " " << b << " " << a * b << endl;
    }
  }
}