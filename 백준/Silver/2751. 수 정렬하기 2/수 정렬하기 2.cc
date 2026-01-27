#include <algorithm>
#include <iostream>

using namespace std;

int arr[1000001] = {
    0,
};
int tmp[1000001] = {
    0,
};
void merge_sort(int a, int b) {
  if (b - a < 1)
    return;

  int m = a + (b - a) / 2;

  merge_sort(a, m);
  merge_sort(m + 1, b);

  int idx1 = a;
  int idx2 = m + 1;
  int k = a;
  while (idx1 <= m && idx2 <= b) {
    if (arr[idx1] < arr[idx2]) {
      tmp[k] = arr[idx1];
      idx1++;
    } else {
      tmp[k] = arr[idx2];
      idx2++;
    }
    k++;
  }

  while (idx1 <= m) {
    tmp[k] = arr[idx1];
    idx1++;
    k++;
  }
  while (idx2 <= b) {
    tmp[k] = arr[idx2];
    idx2++;
    k++;
  } // update 안하면 아무리 tmp를 update해도 원본은 안바뀜 따라서 마지막 단계만
    // 수행 2 1 5 4 3 출력
  for (int i = a; i <= b;
       i++) { // 병합정렬에서 중요한 로직-중간 단계에서 원본 배열 update
    arr[i] = tmp[i];
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  merge_sort(1, n);

  for (int i = 1; i <= n; i++) {
    cout << arr[i] << "\n";
  }
}