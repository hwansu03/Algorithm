#include <algorithm>
#include <iostream>

using namespace std;

int arr[10001] = {
    0,
};
int sum[10001] = {
    0,
}; // 최댓값을 모아둔 배열

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  sum[1] = arr[1];
  sum[2] = arr[1] + arr[2];
  sum[3] = max({arr[1] + arr[2], arr[2] + arr[3], arr[1] + arr[3]});

  for (int i = 4; i <= n; i++) {
    sum[i] = max(
        {sum[i - 2] + arr[i], sum[i - 1], sum[i - 3] + arr[i - 1] + arr[i]});
  }

  cout << sum[n];
}