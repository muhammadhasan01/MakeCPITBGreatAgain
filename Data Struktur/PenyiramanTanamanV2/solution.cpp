/**
* Author  : mhasan01
* Problem : Penyiraman Tanaman (Version 2)
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

void update(int v, int s, int e, int pos, int val) {
    if (s == e && s == pos) {
        segtree[v].maks += val;
        segtree[v].sum += val;
    } else {
        int mid = (s + e) / 2;
        if (pos <= mid) {
            update(2 * v, s, mid, pos, val);
        } else {
            update(2 * v + 1, mid + 1, e, pos, val);
        }
        segtree[v] = merge(segtree[2 * v], segtree[2 * v + 1]);
    }
}

st get(int v, int s, int e, int l, int r) {
    if (e < l || s > r || l > r) {
        // return maks = 0, sum = 0
        return {0, 0};
    }
    if (l <= s && e <= r) {
        return segtree[v];
    }
    int mid = (s + e) / 2;
    st p1 = get(2 * v, s, mid, l, r);
    st p2 = get(2 * v + 1, mid + 1, e, l, r);
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
            int pos;
            cin >> pos;
            update(1, 1, n, pos, 1);
        } else if (tp == 2) {
            int l, r;
            cin >> l >> r;
            st getz = get(1, 1, n, l, r);
            cout << getz.maks << " " << getz.sum << '\n';
        }
    }

    return 0;
}