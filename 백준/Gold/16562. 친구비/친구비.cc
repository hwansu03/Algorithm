#include <iostream>
using namespace std;

int arr[10001] = {
    0,
}; // 비용
int adj[10001]; // 부모를 담는 배열

// 부모가 -1인 node들의 가격의 합이랑 돈을 비교하면 되는 문제
int find_head(int k) {
  if (adj[k] == -1)
    return k;
  adj[k] = find_head(adj[k]); // 재귀문장
  return adj[k];
}

void union_find(int v, int w) {
  int rootv = find_head(v);
  int rootw = find_head(w);

  if (rootv == rootw)
    return;
  if (arr[rootv] <= arr[rootw]) {
    adj[rootw] = rootv;
  } else {
    adj[rootv] = rootw;
  }
}

int main() {
  for (int i = 0; i <= 10000; i++) {
    adj[i] = -1;
  }

  int n, m, k;
  cin >> n >> m >> k;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  int v, w;
  for (int i = 0; i < m; i++) {
    cin >> v >> w;
    union_find(v, w);
  }

  int result = 0;
  for (int i = 1; i <= n; i++) {
    if (adj[i] == -1) {
      result += arr[i];
    }
  }
  if (result <= k) {
    cout << result << endl;
  } else {
    cout << "Oh no" << endl;
  }
}