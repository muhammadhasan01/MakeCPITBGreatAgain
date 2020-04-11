### Solusi Imba Berbaris (Version 1) oleh Muhammad Hasan

Solusi kali ini cukup *straightforward* saja, kita tinggal bruteforce dengan menggunakan for loop dua kali

<details><summary><b>Kode Solusi:</b></summary>

``` C++
/**
* Author  : mhasan01
* Problem : Imba Berbaris (Version 1)
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

int n;
int M[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> M[i];
    }
    for (int i = 1; i <= n; i++) {
        int res = 0;
        for (int j = i - 1; j >= 1; j--) {
            if (M[i] >= M[j]) res++;
        }
        cout << res << (i == n ? '\n' : ' ');
    }

    return 0;
}
```

</details>