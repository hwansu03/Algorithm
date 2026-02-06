#include <iostream>
using namespace std;

int ans[8] = {
    0,
};

int m, n;
void backtrack(int k, int idx) {

  ans[idx] = k;

  if (idx == m) {
    for (int i = 1; i <= m; i++) {
      cout << ans[i] << " ";
    }
    cout << '\n';
    return;
  }
  for (int i = 1; i <= n; i++) {
    backtrack(i, idx + 1);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    backtrack(i, 1);
  }
}