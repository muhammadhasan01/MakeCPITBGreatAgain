/**
* Author  : mhasan01
* Problem : Imba Berbaris (Version 2)
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
long long M[N];
int bit[N];

unordered_map<long long, int> mp;
set<int> st;

void add(int x) {
    for ( ; x <= n; x += x & -x) bit[x]++;
}

int get(int x) {
    if (x == 0) return 0;
    int ret = 0;
    for ( ; x > 0; x -= x & -x) ret += bit[x];
    return ret;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> M[i];
        st.insert(M[i]);
    }
    int ord = 0;
    for (auto e : st) {
        mp[e] = ++ord;
    }
    for (int i = 1; i <= n; i++) {
        cout << get(mp[M[i]]) << (i == n ? '\n' : ' ');
        add(mp[M[i]]);
    }

    return 0;
}