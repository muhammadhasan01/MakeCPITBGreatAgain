/**
 * Author  : Morgen Sudyanto
 * Problem : Tugas Besar Mufraswid
 */
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<LL,LL>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL r,c;
    cin >> r >> c;
    LL a[r+5][c+5];
    LL dp[r+5][c+5];
    memset (dp,0,sizeof(dp));
    for (LL i=1;i<=r;i++) {
        for (LL j=1;j<=c;j++) {
            cin >> a[i][j];
            dp[i][j] = a[i][j];
        }
    }
    for (LL i=1;i<=r;i++) {
        for (LL j=1;j<=c;j++) {
            dp[i][j] += dp[i][j-1];
        }
    }
    for (LL i=1;i<=r;i++) {
        for (LL j=1;j<=c;j++) {
            dp[i][j] += dp[i-1][j];
        }
    }
    LL ans = 0;
    for (LL i=1;i<=r;i++) {
        for (LL j=1;j<=c;j++) {
            for (LL k=i;k<=r;k++) {
                for (LL l=j;l<=c;l++) {
                    ans = max(ans, dp[k][l] - dp[i-1][l] - dp[k][j-1] + dp[i-1][j-1]);
                }
            }
        }
    }
    if (ans == 0) {
        ans = INT_MIN;
        for (LL i=1;i<=r;i++) {
            for (LL j=1;j<=c;j++) {
                ans = max(ans, a[i][j]);
            }
        }
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}