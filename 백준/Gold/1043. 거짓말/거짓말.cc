#include <iostream>
#include <vector>

using namespace std;

int arr[51];
vector<vector<int>> again;

int Find(int x) {
  if (arr[x] == x)
    return x;

  return arr[x] = Find(arr[x]);
}

void Union(int a, int b) {
  int rootA = Find(a);
  int rootB = Find(b);

  if (rootA == rootB)
    return;

  if (rootA < rootB) {
    arr[rootB] = rootA;
  } else {
    arr[rootA] = rootB;
  }
}

int main() {
  int n, m;
  cin >> n >> m; // 사람, 파티
  again.resize(m);

  for (int i = 1; i <= n; i++) {
    arr[i] = i;
  }

  int cnt = 0; // 정답
  int num;
  cin >> num;

  int tmp;
  for (int i = 0; i < num; i++) {
    cin >> tmp;
    arr[tmp] = 0;
  }

  for (int i = 0; i < m; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int p;
      cin >> p;
      again[i].push_back(p);
    }

    for (int j = 0; j < k - 1; j++) {
      Union(again[i][j], again[i][j + 1]);
    }
  }

  for (int i = 0; i < m; i++) {
    if (Find(again[i][0]) != 0) {
      cnt++;
    }
  }
  cout << cnt << endl;
}
