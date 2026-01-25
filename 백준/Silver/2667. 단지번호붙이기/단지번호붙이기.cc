#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// 재귀를 이용한 dfs로 풀어보기 목표
using namespace std;

int arr[25][25] = {
    0,
};
bool visited[25][25] = {false};

vector<int> ans;
int n;
int cnt;
void dfs(int a, int b) {

  visited[a][b] = true;
  cnt++;

  int x[4] = {-1, 0, 1, 0};
  int y[4] = {0, -1, 0, 1};

  for (int i = 0; i < 4; i++) {
    int a_x = a + x[i];
    int b_y = b + y[i];
    if (a_x < 0 || b_y < 0 || a_x >= n || b_y >= n)
      continue;
    if (arr[a_x][b_y] != 0 && visited[a_x][b_y] == false)
      dfs(a_x, b_y);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < n; j++) {
      arr[i][j] = s[j] - '0';
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (arr[i][j] == 1 && visited[i][j] == false) {
        cnt = 0;
        dfs(i, j);
        ans.push_back(cnt);
      }
    }
  }

  /*cout << endl << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << arr[i][j];
    }
    cout << endl;
  }*/

  cout << ans.size() << endl;
  sort(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << endl;
  }
}