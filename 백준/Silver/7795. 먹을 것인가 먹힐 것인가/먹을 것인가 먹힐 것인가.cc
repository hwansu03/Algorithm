#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    vector<int> a;
    vector<int> b;
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
      int num;
      cin >> num;
      a.push_back(num);
    }
    for (int i = 0; i < m; i++) {
      int num;
      cin >> num;
      b.push_back(num);
    }
    sort(a.begin(), a.begin() + n);
    sort(b.begin(), b.begin() + m);

    int idxA = n - 1;
    int idxB = m - 1;
    int result = 0;

    while (idxA >= 0) { // 투포인터
      if (a[idxA] <= b[idxB]) {
        if (idxB == 0)
          idxA--;

        else
          idxB--;

      } else {
        result += idxB + 1;
        idxA--;
      }
    }
    cout << result << endl;
  }
}