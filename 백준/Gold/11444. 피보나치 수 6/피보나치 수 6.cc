#include <iostream>
#include <vector>
using namespace std;
#define mod 1000000007
// 배열 없이 분할정복으로 unsigned long long으로 풀기?

typedef vector<vector<unsigned long long>> matrix;
matrix mul1 = {{1, 1}, {1, 0}};
matrix nums = {{1, 0}, {0, 0}};

matrix matmul(matrix a, matrix b) { // 행렬의 곱셈
  matrix c = {{0, 0}, {0, 0}};
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        c[i][j] += (a[i][k] * b[k][j]) % mod;
      }
      c[i][j] %= mod;
    }
  }
  return c;
}

matrix dp(unsigned long long n) {
  if (n == 0) {
    return {{1, 0}, {0, 1}};
  }
  if (n == 1) {
    return mul1;
  }

  matrix t = dp(n / 2);
  if (n % 2 == 1) {
    return matmul(matmul(t, t), mul1);
  } else {
    return matmul(t, t);
  }
}

int main() {
  unsigned long long n;

  cin >> n;
  if (n == 0) {
    cout << 0 << endl;
  } else {
    matrix fibo1 = dp(n - 1);
    matrix ans = matmul(fibo1, nums);

    cout << ans[0][0];
  }
}
// 4000000028
/// 4*256*1024