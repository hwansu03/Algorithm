#include <algorithm>
#include <cmath>
#include <iostream>
#define MAX 2188

using namespace std;

char ans[MAX][MAX];

int n;

void recursive(int n1, int n2, int size) {
  if (size <= 3)
    return;

  for (int k = n1 + size / 3; k < n1 + size / 3 * 2; k++) {
    for (int p = n2 + size / 3; p < n2 + size / 3 * 2;
         p++) {
      ans[k][p] = ' ';
    }
  }

  for (int k = n1; k <= n1 + 2 * size / 3; k += size / 3) {
    for (int p = n2; p <= n2 + 2 * size / 3; p += size / 3) {
      recursive(k, p, size / 3);
    }
  }
}

int main() {

  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i % 3 == 2 && j % 3 == 2) {
        ans[i][j] = ' ';
      } else {
        ans[i][j] = '*';
      }
    }
  }
  recursive(1, 1, n);

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << ans[i][j];
    }
    cout << endl;
  }
}