#include <iostream>
#include <string>
#include <vector>

using namespace std;

string bomb;
vector<char> ans;

int main() {

  string s;
  cin >> s;
  cin >> bomb;
  bool isbomb = true;

  for (int i = 0; i < s.size(); i++) {
    ans.push_back(s[i]);

    while (ans.size() >= bomb.length()) {
      int idx = ans.size() - 1;
      for (int j = 0; j < bomb.size();
           j++) { // int j = idx; j >= idx - bomb.length(); j--
        if (ans[ans.size() - 1 - j] != bomb[bomb.size() - 1 - j]) {
          isbomb = false;
          break;
        }
      }
      if (isbomb) {
        for (int j = 0; j < bomb.length(); j++) {
          ans.pop_back();
        }
      } else
        break;
    }
    isbomb = true;
  }

  if (ans.empty()) {
    cout << "FRULA";
  } else {
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i];
    }
  }
}