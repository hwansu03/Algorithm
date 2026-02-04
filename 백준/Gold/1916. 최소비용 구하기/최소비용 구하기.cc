#include <iostream>
#include <queue>
#include <vector>

#define MAX 100000001
using namespace std;

typedef pair<unsigned long long, unsigned long long> node; // 거리, 도착점
vector<node> adj[1001];                                    // 인접행렬
unsigned long long d[1001];                                // 비용

void init() {
  for (int i = 0; i <= 1000; i++) {
    adj[i].clear();
    d[i] = MAX;
  }
}

void dijkstra(int start) {
  d[start] = 0;

  priority_queue<node, vector<node>, greater<node>> pq;
  pq.push(pair(0, start));

  while (!pq.empty()) {
    node t = pq.top();
    pq.pop();
    if (t.first > d[t.second])
      continue; // 거리가 원래 거리보다 이미 더 크면 바로 넘기기
    for (node &n : adj[t.second]) {
      if (d[t.second] + n.first < d[n.second]) {
        d[n.second] = d[t.second] + n.first;
        pq.push(pair(d[n.second], n.second));
      } else {
        continue;
      }
    }
  }
}

int main() {
  init();
  int n, m;
  cin >> n >> m;
  int src, dst, fee;

  while (m--) {
    cin >> src >> dst >> fee;
    adj[src].push_back(pair(fee, dst));
  }

  int start, end;
  cin >> start >> end;
  dijkstra(start);
  cout << d[end] << endl;
}