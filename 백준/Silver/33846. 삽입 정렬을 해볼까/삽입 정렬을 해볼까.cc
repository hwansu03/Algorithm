#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<int> a;
  int n, t;
  cin >> n >> t;

  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    a.push_back(num);
  }

  sort(a.begin(), a.begin() + t);

  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
}

/*void insertion_sort(vector<int> &a, int t) {

  for (int i = 1; i < t; i++) {
    int k = i;
    int tmp = a[i];
    for (int j = i - 1; j >= 0; j--) {
      if (a[j] > a[i]) {
        k = j;
      }
    }

    if (k != i) {
      for (int p = i - 1; p >= k; p--) {
        a[p + 1] = a[p];
      }
      a[k] = tmp;
    }
  }
}*/