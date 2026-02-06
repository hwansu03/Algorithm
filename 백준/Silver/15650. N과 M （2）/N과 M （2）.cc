#include <iostream>
using namespace std;

int ans[9] = {
    0,
};

int m, n;                        // 1~n까지 m개를 고름
void backtrack(int k, int idx) { // 이전자리 숫자 , idx번째 자리
  ans[idx] = k;

  if (idx == m) {
    for (int i = 1; i <= m; i++) {
      cout << ans[i] << " ";
    }
    cout << endl;
    return;
  }
  for (int i = k + 1; i <= n; i++) {
    backtrack(i, idx + 1);
  }
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n - m + 1; i++) {
    backtrack(i, 1); // 1번째 자리는 i
  }
}