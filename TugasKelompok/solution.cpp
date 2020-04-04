/**
* Author  : Kamal Shafi
* Problem : Tugas Kelompok
*/

// Pengenalan DSU
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int n, m;
int par[N], sz[N];

int find(int a){
    if (par[a] == a) return a;
    return par[a] = find(par[a]);
}

void make(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    par[b] = a;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=n;i++){
        par[i] = i;
        sz[i] = 1;
    }
    for (int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        make(a, b);
    }

    int ans = 0;
    for (int i=1;i<=n;i++){
        if (par[i] == i) ans++;
    }
    cout << ans << endl;

    return 0;
}