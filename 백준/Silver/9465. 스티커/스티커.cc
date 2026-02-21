#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int sticker[100001][2];
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < n; j++) {
        cin >> sticker[j][i];
      }
    }
    sticker[1][0] += sticker[0][1];
    sticker[1][1] += sticker[0][0];
    int ans = -1;
    for (int i = 2; i < n; i++) {
      sticker[i][0] =
          max({sticker[i - 1][1], sticker[i - 2][0], sticker[i - 2][1]}) +
          sticker[i][0];
      sticker[i][1] =
          max({sticker[i - 1][0], sticker[i - 2][0], sticker[i - 2][1]}) +
          sticker[i][1];
    }

    if (sticker[n - 1][0] > sticker[n - 1][1]) {
      ans = sticker[n - 1][0];
    } else {
      ans = sticker[n - 1][1];
    }

    cout << ans << endl;
  }
}