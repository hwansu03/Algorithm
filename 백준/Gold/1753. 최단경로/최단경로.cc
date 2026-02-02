#include <iostream>
#include <queue>
#define MAX 7000000000
using namespace std;

typedef pair<int, int> node; // 거리, 도착점
vector<node> adj[20001];
long long dist[20001]; // 거리를 나타내는 배열

void init() {
  for (int i = 0; i <= 20000; i++) {
    dist[i] = MAX;
    adj[i].clear();
  }
}
void dijkstra(int k) {
  priority_queue<node, vector<node>, greater<node>> pq;
  pq.push(pair(0, k));
  dist[k] = 0;
  while (!pq.empty()) {
    node n = pq.top();
    pq.pop();

    for (node &t : adj[n.second]) {
      if (dist[n.second] + t.first < dist[t.second]) {
        dist[t.second] = dist[n.second] + t.first;
        pq.push(pair(dist[n.second] + t.first, t.second));
      } else
        continue;
    }
  }
}

int main() {
  init();
  int v, e;
  cin >> v >> e;
  int k;
  cin >> k;

  for (int i = 0; i < e; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back(pair(w, v));
  }

  dijkstra(k);

  for (int i = 1; i <= v; i++) {
    if (dist[i] == MAX) {
      cout << "INF" << endl;
    } else
      cout << dist[i] << endl;
  }
}