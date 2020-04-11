### Solusi Cegah Penyebaran Corona oleh Morgen Sudyanto

Jawaban dari soal ini adalah: jumlah total semua node - jumlah node yang di "block" oleh sebuah node hijau.

Jumlah total semua node dapat dihitung dengan rumus :

$$ \frac{k^h - 1}{k - 1} $$

Perhitungan dapat dilakukan dengan memanfaatkan [modulo inverse](https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/).

Sedangkan jumlah node yang berwarna hijau dan putih (penduduk yang tidak terinfeksi) dapat dihitung dengan cara yang sama seperti yang pertama, tetapi dengan nilai $$ h $$ yang berbeda. Node yang sebelumnya sudah dihitung juga tidak boleh masuk lagi ke dalam perhitungan (seperti node $$ 5 $$ pada gambar contoh - node $$ 5 $$ berada di dalam subtree node $$ 2 $$). Untuk mengeceknya, kita bisa menggunakan struktur data [set](https://www.topcoder.com/community/competitive-programming/tutorials/power-up-c-with-the-standard-template-library-part-1/#set) atau [map](https://www.topcoder.com/community/competitive-programming/tutorials/power-up-c-with-the-standard-template-library-part-1/#map). 

Pertama, kita sort dulu arraynya agar kita dapat mengunjungi node yang berada di atas terlebih dahulu. Lalu, cek apakah node tersebut sudah pernah dikunjungi. Caranya adalah dengan mencari parent dari node sampai mencapai node $$ 0 $$. Jika ada parent yang sudah pernah dikunjungi, berarti kita dapat men-skip node tersebut. Jika tidak, kita kurangkan jawaban sebesar size subtree dengan node tersebut sebagai rootnya, lalu menandakan bahwa node tersebut telah dikunjungi.

Selain itu, ada kasus khusus yaitu bila $$ k $$ bernilai $$ 1 $$ (kira - kira kenapa hayo).

<details><summary><b>Kode Solusi:</b></summary>

``` C++
/**
 * Author  : Morgen Sudyanto
 * Problem : Cegah Penyebaran Corona
 */
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<int,int>
#define LL long long
using namespace std;

LL fpow(LL a, LL b) {
    LL ret = 1;
    while (b) {
        if (b & 1) {
            ret = ret * a;
            ret %= MOD;
        }
        b /= 2;
        a = a * a;
        a %= MOD;
    }
    return ret;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL k, h;
    cin >> k >> h;
    int n;
    cin >> n;
    LL a[n+5];
    int level[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    sort (a+1,a+n+1);
    if (k == 1) {
        cout << a[1]%MOD << endl;
        return 0;
    }
    vector<pair<LL,LL>> groups;
    LL l = 0, cnt = 1, cnth = 0;
    while (l <= 1e12 && cnth < h) {
        groups.pb({l, l + cnt - 1});
        l += cnt;
        cnt *= k;
        cnth++;
    }

    // for (int i=0;i<groups.size();i++) cout << groups[i].fi << " " << groups[i].se << endl;

    for (int i=1;i<=n;i++) {
        for (int j=0;j<groups.size();j++) {
            if (a[i] >= groups[j].fi && a[i] <= groups[j].se) {
                level[i] = j;
                break;
            }
        }
    }

    // for (int i=1;i<=n;i++) cout << level[i] << " ";
    // cout << endl;

    for (int i=1;i<=n;i++) a[i] -= groups[level[i]].fi;
    
    // for (int i=1;i<=n;i++) cout << a[i] << " ";
    // cout << endl;

    LL ans = ((fpow(k, h) - 1) * fpow(k - 1, MOD - 2)) % MOD;
    map<LL, map<LL, int>> done;
    for (int i=1;i<=n;i++) {
        int curlevel = level[i], curid = a[i];
        bool y = 1;
        while (curlevel >= 0) {
            if (done[curlevel][curid] == 1) {
                y = 0;
                break;
            }
            curlevel--;
            curid /= k;
        }
        if (y) {
            done[level[i]][a[i]] = 1;
            ans -= (fpow(k, h - level[i]) - 1) * fpow(k - 1, MOD - 2);
            ans %= MOD;
        }
    }
    ans += MOD;
    ans %= MOD;
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}

```

</details>