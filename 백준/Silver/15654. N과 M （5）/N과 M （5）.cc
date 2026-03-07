#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
int ans[9] = {
    // 1-based arr
    0,
};
bool visited[9]; // 0-based arr
vector<int> v;

void backtrack(int idx, int size) { // 인덱스와 자리수

  ans[size] = v[idx]; // 처음에 idx는 0 size는 1 입력
  visited[idx] = true;

  if (size == m) {
    for (int i = 1; i <= size; i++) {
      cout << ans[i] << " ";
    }
    cout << "\n";
    return;
  }

  for (int i = 0; i < v.size(); i++) {
    if (visited[i] == true)
      continue;
    backtrack(i, size + 1);
    visited[i] = false;
  }
  visited[idx] = false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < 9; i++) {
    visited[i] = false;
  }
  int tmp;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    v.push_back(tmp);
  }

  sort(v.begin(), v.end());

  for (int i = 0; i < v.size(); i++) {
    backtrack(i, 1);
  }
}

// 1234 1243 1324 1342 1423 1432