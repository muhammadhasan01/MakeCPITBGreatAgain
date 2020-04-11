### Solusi Imba Berbaris (Version 2) oleh Muhammad Hasan

Kita tidak bisa menggunakan Bruteforce kali ini. Sehingga diperlukan data struktur tertentu. Untuk menyelesaikan soal ini kita bisa gunakan **[Segment Tree](https://cp-algorithms.com/data_structures/segment_tree.html)** atau dengan **[Fenwick Tree/BIT](https://cp-algorithms.com/data_structures/fenwick.html)**. Di kode solusi kali ini, kita akan gunakan BIT saja karena lebih mudah diimplementasi. Untuk setiap query kita lakukan *get* untuk mencari nilai yang kurang dari sama dengan `M[i]`, setelah itu baru kita update BIT kita dengan *add* `M[i]`.

<details><summary><b>Kode Solusi:</b></summary>

``` C++
/**
* Author  : mhasan01
* Problem : Imba Berbaris (Version 2)
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
int M[N];
int bit[N];

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
    }
    for (int i = 1; i <= n; i++) {
        cout << get(M[i]) << (i == n ? '\n' : ' ');
        add(M[i]);
    }

    return 0;
}
```

</details>