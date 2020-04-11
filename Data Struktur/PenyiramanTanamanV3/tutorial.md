### Solusi Penyiraman Tanaman (Version 3) oleh Muhammad Hasan

Kali ini kita butuh *update range*, maka kita perlu data struktur lebih advance. Kita bisa selesaikan soal ini dengan **[Segment Tree Lazy Propagation](https://cp-algorithms.com/data_structures/segment_tree.html)**. Untuk implementasinya bisa dilihat di kode solusi ini.

<details><summary><b>Kode Solusi:</b></summary>

``` C++
/**
* Author  : mhasan01
* Problem : Penyiraman Tanaman (Version 3)
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

struct st {
    long long maks, sum;
};

int n, q;
long long T[N];
st segtree[4 * N];
st lazy[4 * N];

st merge(st a, st b) {
    st ret;
    ret.maks = max(a.maks, b.maks);
    ret.sum = a.sum + b.sum;
    return ret;
}

void build(int v, int s, int e) {
    if (s == e) {
        // create maks = T[s] and sum = T[s]
        segtree[v] = {T[s], T[s]};
    } else {
        int mid = (s + e) / 2;
        build(2 * v, s, mid);
        build(2 * v + 1, mid + 1, e);
        segtree[v] = merge(segtree[2 * v], segtree[2 * v + 1]);
    }
}

void push(int v, int s, int e) {
    if (lazy[v].maks == 0 && lazy[v].sum == 0) return;
    if (s == e) return;
    
    // update maks
    segtree[2 * v].maks += lazy[v].maks;
    segtree[2 * v + 1].maks += lazy[v].maks;
    lazy[2 * v].maks += lazy[v].maks;
    lazy[2 * v + 1].maks += lazy[v].maks;

    // update sum
    int mid = (s + e) / 2;
    segtree[2 * v].sum += (mid - s + 1) * (lazy[v].sum); 
    segtree[2 * v + 1].sum += (e - (mid + 1) + 1) * (lazy[v].sum);
    lazy[2 * v].sum += lazy[v].sum;
    lazy[2 * v + 1].sum += lazy[v].sum;

    // update this lazy to zero
    lazy[v].maks = 0;
    lazy[v].sum = 0;
}

void updateRange(int v, int s, int e, int l, int r, int val) {
    if (l > r) return;
    if (l == s && e == r) {
        // update max
        segtree[v].maks += val;
        lazy[v].maks += val;

        // update sum
        segtree[v].sum += (e - s + 1) * val;
        lazy[v].sum += val;

        // terminate
        return;
    }
    // propagate
    push(v, s, e);

    int mid = (s + e) / 2;
    updateRange(2 * v, s, mid, l, min(r, mid), val);
    updateRange(2 * v + 1, mid + 1, e, max(l, mid + 1), r, val);

    segtree[v] = merge(segtree[2 * v], segtree[2 * v + 1]);
}

st get(int v, int s, int e, int l, int r) {
    if (l > r) return {0, 0};
    if (l <= s && e <= r) {
        return segtree[v];
    }
    // propagate
    push(v, s, e);

    int mid = (s + e) / 2;
    st p1 = get(2 * v, s, mid, l, min(r, mid));
    st p2 = get(2 * v + 1, mid + 1, e, max(l, mid + 1), r);

    return merge(p1, p2);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> T[i];
    }
    build(1, 1, n);
    cin >> q;
    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int l, r;
            cin >> l >> r;
            updateRange(1, 1, n, l, r, 1);
        } else if (tp == 2) {
            int l, r;
            cin >> l >> r;
            st getz = get(1, 1, n, l, r);
            cout << getz.maks << " " << getz.sum << '\n';
        }
    }

    return 0;
}
```

</details>