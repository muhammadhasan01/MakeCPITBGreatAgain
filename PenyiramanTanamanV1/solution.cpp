/**
* Author  : mhasan01
* Problem : Penyiraman Tanaman (Version 1)
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

int n, q;
int T[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> T[i];
    }
    cin >> q;
    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int pos;
            cin >> pos;
            T[pos]++;
        } else if (tp == 2) {
            int l, r;
            cin >> l >> r;
            int maks = T[l], sum = 0;
            for (int i = l; i <= r; i++) {
                maks = max(maks, T[i]);
                sum += T[i];
            }
            cout << maks << " " << sum << '\n';
        }
    }

    return 0;
}