### Solusi Penyebaran Corona (Version 1) oleh Muhammad Hasan

Soal ini cukup standar, kita hanya perlu melakukan dfs atau bfs dimulai dari **root** (pada kasus ini **root** = 1), lalu pada *traversal* tersebut kita catat jarak *root* ke node. Kodenya adalah sebagai berikut:

``` C++
/**
* Author  : mhasan01
* Problem : Penyebaran Corona (Version 1)
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
vector<int> g[N];
int dist[N];

void dfs(int u, int p) {
  for (auto v : g[u]) {
    if (v == p) continue;
    dist[v] = dist[u] + 1;
    dfs(v, u);
  }
}

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dist[1] = 0;
  dfs(1, 1);
  for (int i = 2; i <= n; i++) {
    cout << dist[i] << '\n';
  }

  return 0;
}
```

**Catatan**: Implementasi DFS tersebut baiknya tidak digunakan selain graf yang berbentuk *tree*