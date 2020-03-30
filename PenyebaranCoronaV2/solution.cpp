/**
* Author  : mhasan01
* Problem : Penyebaran Corona (Version 2)
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int L = ceil(log2(N)) + 5;

int n, q;
vector<int> g[N];
int up[N][L];
int tin[N], tout[N], tim = 0;
int dist[N];

void dfs(int u, int p) {
  up[u][0] = p;
  for (int i = 1; i < L; i++) {
    up[u][i] = up[up[u][i - 1]][i - 1];
  }
  tin[u] = ++tim;
  for (auto v : g[u]) {
    if (v == p) continue;
    dist[v] = dist[u] + 1;
    dfs(v, u);
  }
  tout[u] = ++tim;
}

bool is_ancestor(int u, int v) {
  return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

int lca(int u, int v) {
  if (is_ancestor(u, v)) return u;
  if (is_ancestor(v, u)) return v;
  for (int i = L - 1; i >= 0; i--) {
    if (!is_ancestor(up[u][i], v)) {
      u = up[u][i];
    }
  }
  return up[u][0];
}

int distance(int u, int v) {
  return dist[u] + dist[v] - 2 * dist[lca(u, v)];
}

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> q;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dist[1] = 0;
  dfs(1, 1);
  while (q--) {
    int u, v;
    cin >> u >> v;
    cout << distance(u, v) << '\n';
  }

  return 0;
}