#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  long long arr[100001];
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  sort(arr + 1, arr + n +1);// n번째까지 정렬
  int start = 1; 
  int end = n;
  long long tmp = 2000000001; 
  int ans1 = start;
  int ans2 = end;

  while (start < end) {
    if (abs(arr[start] + arr[end]) < abs(tmp)) {
      tmp = arr[start] + arr[end];
      ans1 = start;
      ans2 = end;
    }
    if (arr[start] + arr[end] > 0) {
      end--;
    } else if (arr[start] + arr[end] < 0) {
      start++;
    } else {
      break;
    }
  }
  if (arr[ans1] < arr[ans2]) { // 음수인 경우 문제 발생
    cout << arr[ans1] << " " << arr[ans2] << endl;
  } else {
    cout << arr[ans2] << " " << arr[ans1] << endl;
  }
}