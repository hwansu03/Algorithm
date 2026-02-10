#include <algorithm>
#include <iostream>

using namespace std;

int dp[502][502];

int main() {
  int n;
  cin >> n;

  int ans = -1;

  for (int i = 1; i <= n; i++) {   // 세로
    for (int j = 1; j <= i; j++) { // 가로
      cin >> dp[i][j];
    }
  }
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      dp[i][j] = max(dp[i - 1][j - 1] + dp[i][j], dp[i - 1][j] + dp[i][j]);
    }
  }

  for (int i = 1; i <= n; i++) {
    if (dp[n][i] > ans) {
      ans = dp[n][i];
    }
  }
  cout << ans;
}