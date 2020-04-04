/**
* Author  : mhasan01
* Problem : Naik Tangga (Version 1)
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int M = 1e9 + 7;

int n, q;
int fib[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    fib[0] = 1, fib[1] = 1;
    for (int i = 2; i <= n; i++) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % M;
    }
    while (q--) {
        int x;
        cin >> x;
        cout << fib[x] << '\n';
    }

    return 0;
}