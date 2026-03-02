#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  int arr[3];
  int MA[3] = {0, 0, 0};
  int mi[3] = {0, 0, 0};

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> arr[j];
    }
    int t1 = MA[0];
    int t2 = MA[1];
    int t3 = MA[2];
    int u1 = mi[0];
    int u2 = mi[1];
    int u3 = mi[2];
    MA[0] = max(t1, t2) + arr[0];
    mi[0] = min(u1, u2) + arr[0];

    MA[1] = max({t1, t2, t3}) + arr[1];
    mi[1] = min({u1, u2, u3}) + arr[1];

    MA[2] = max(t3, t2) + arr[2];
    mi[2] = min(u3, u2) + arr[2];
  }

  cout << max({MA[0], MA[1], MA[2]}) << " " << min({mi[0], mi[1], mi[2]});
}