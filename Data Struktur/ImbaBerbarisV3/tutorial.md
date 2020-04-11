### Solusi Imba Berbaris (Version 3) oleh Muhammad Hasan

Jika Anda berhasil menyelesaikan Version 2, maka Version 3 ini sebenarnya mudah saja. Kita tinggal urutkan terlebih dahulu nilai-nilai $$ M_i $$-nya, bisa dengan `pair<int, int>` lalu di `sort` kemudian dimasukkan ke `unordered_map<int, int>` atau `map<int, int>`. Kali ini saya urutkan dengan memasukkannya ke dalam `set`, kemudian iterate set tersebut sambil menghitung urutannya, lalu di masukkan ke dalam `unordered_map<int, int>` urutannya.

<details><summary><b>Kode Solusi:</b></summary>

``` C++
/**
* Author  : mhasan01
* Problem : Imba Berbaris (Version 3)
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
long long M[N];
int bit[N];

set<long long> st;
unordered_map<long long, int> mp;

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
```

</details>