#include <algorithm>
#include <iostream>

using namespace std;

long long arr[500001] = {
    0,
};
long long ans = 0;
long long tmp[500001] = {
    0,
};

void merge_sort(long long a, long long b) {
  if (b - a < 1)
    return;

  int m = a + (b - a) / 2;
  merge_sort(a, m);
  merge_sort(m + 1, b);

  long long idx1 = a;
  long long idx2 = m + 1;
  long long k = a;
  while (idx1 <= m && idx2 <= b) {
    if (arr[idx1] <= arr[idx2]) {
      tmp[k++] = arr[idx1++];
    } else {               // 오른쪽이 왼쪽보다 작은 경우
      ans += m - idx1 + 1; // swap 발생
      tmp[k++] = arr[idx2++];
    }
  }
  while (idx1 <= m) {
    tmp[k++] = arr[idx1++];
  }
  while (idx2 <= b) {
    tmp[k++] = arr[idx2++];
  }

  for (long long i = a; i <= b; i++) {
    arr[i] = tmp[i];
  }
}

int main() {
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  merge_sort(1, n);

  cout << ans << endl;
}