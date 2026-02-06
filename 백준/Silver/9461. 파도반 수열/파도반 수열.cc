#include <algorithm>
#include <iostream>

using namespace std;

static long long ans[101];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ans[1] = 1;
  ans[2] = 1;
  ans[3] = 1;
  ans[4] = 2;
  ans[5] = 2;
  for (int i = 6; i <= 100; i++) {
    ans[i] = ans[i - 1] + ans[i - 5];
  }

  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    cout << ans[n] << endl;
  }
}