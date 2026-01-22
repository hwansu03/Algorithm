#include <iostream>
using namespace std;

char ans[3500][6300];

void recursive(int n1, int n2, int size) {
  if (size == 3) {
    ans[n1][n2] = '*';

    ans[n1 + 1][n2 - 1] = '*';
    ans[n1 + 1][n2 + 1] = '*';

    for (int i = 0; i < 5; i++) {
      ans[n1 + 2][n2 - 2 + i] = '*';
    }
    return;
  }

  recursive(n1 + size / 2, n2 - size / 2, size / 2);
  recursive(n1 + size / 2, n2 + size / 2, size / 2);
  recursive(n1, n2, size / 2);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2 * n - 1; j++) {
      ans[i][j] = ' ';
    }
  }

  recursive(0, n - 1, n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2 * n - 1; j++) {
      cout << ans[i][j];
    }
    cout << endl;
  }
}
