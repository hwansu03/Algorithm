#include <iostream>
#include <vector>
using namespace std;

char tree[27][3];

void preorder(char a) {

  if (a != '.')
    cout << a;

  if (a != '.')
    preorder(tree[int(a) - 65][1]);

  if (a != '.')
    preorder(tree[int(a) - 65][2]);
}

void Inorder(char a) {
  if (a != '.')
    Inorder(tree[int(a) - 65][1]);

  if (a != '.')
    cout << a;

  if (a != '.')
    Inorder(tree[int(a) - 65][2]);
}

void postorder(char a) {
  if (a != '.')
    postorder(tree[int(a) - 65][1]);

  if (a != '.')
    postorder(tree[int(a) - 65][2]);

  if (a != '.')
    cout << a;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    char a, b, c;
    cin >> a >> b >> c;
    tree[int(a) - 65][1] = b;
    tree[int(a) - 65][2] = c;
  }

  preorder('A');
  cout << endl;
  Inorder('A');
  cout << endl;
  postorder('A');
}