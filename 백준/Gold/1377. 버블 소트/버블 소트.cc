#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> arr(n);

  int num;
  for (int i = 0; i < n; i++) {
    cin >> arr[i].first;
    arr[i].second = i;
  }

  sort(arr.begin(), arr.end());
  /*sort는 pair 처리시 first가 작은 것이 앞으로, first가 같으면 second가 작은 것이 앞으로 온다.*/

  int max = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i].second - i > max) {
      max = arr[i].second - i;
    }
  }
  cout << max + 1 << endl;
}