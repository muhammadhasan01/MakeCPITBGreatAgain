### Solusi Potong Kue oleh Muhammad Kamal Shafi

Perhatikan bahwa yang penting adalah posisi kolom setiap topping. Solusinya cukup mudah, untuk setiap kolom yang pilih, kita hitung ada berapa banyak topping di kolom sebelah kiri dan di kolom sebelah kanan kemudian hitung selisihnya. Dari semua kemungkinan pemilihan kolom itu, kita ambil selisih yang minimum. Tentunya mencoba semua kemungkinan lalu Brutefoce tidak baik, ini akan menghasilkan waktu $$ O (N^2) $$. Cara yang baik adalah dengan **Precompute Prefix Sum** dan **Suffix Sum**. Sehingga total kompleksitas menjadi $$ O (N) $$

<details><summary><b>Kode Solusi:</b></summary>

``` C++
/**
* Author  : Kamal Shafi
* Problem : Potong Kue
*/
#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int N = 1e5 + 10;

int n, m, k;
int ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for (int i=1;i<=k;i++){
        int a, b;
        cin >> a >> b;
        ar[b]++;
    }

    for (int i=1;i<=m;i++){
        ar[i] += ar[i - 1];
    }

    int ans = INF;
    for (int i=1;i<m;i++){
        ans = min(ans, abs(ar[m] - 2 * ar[i]));
    }
    cout << ans << endl;

    return 0;
}
```

</details>