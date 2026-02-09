#include <algorithm>
#include <iostream>

using namespace std;

int arr[1001];
int dp[1001];

int main() {
  int n;
  cin >> n;

  for (int i = 1; i <= 1000; i++) {
    arr[i] = 0;
    dp[i] = 1;
  }

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  int total_max = 0;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      if (arr[j] < arr[i]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    if (total_max < dp[i]) {
      total_max = dp[i];
    }
  }

  cout << total_max << endl;
  return 0;
}