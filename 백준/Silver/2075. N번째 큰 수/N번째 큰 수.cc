#include <iostream>
#include <queue>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  priority_queue<int, vector<int>, greater<int>> pq;
  int n;
  cin >> n;
  int num;
  for (int i = 0; i < n; i++) {
    cin >> num;
    pq.push(num);
  }

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> num;
      pq.push(num);
      pq.pop();
    }
  }
  cout << pq.top();
}