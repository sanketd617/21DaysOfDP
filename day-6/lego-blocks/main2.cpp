#include <iostream>
#include <cmath>

using namespace std;

#define MOD 1000000007

typedef long long LL;

vector <LL> dp1(1001, -1);

LL pow(LL a, LL p) {
    LL ans = 1;
    while (p) {
        if (p % 2) ans = ans * a % MOD;
        a = (a * a) % MOD;
        p /= 2;
    }
    return ans;
}

LL allWays(LL m) {
    if (m < 0) return 0;
    if (m == 0) return 1;
    if (dp1[m] != -1) return dp1[m];
    return dp1[m] = (
                            (allWays(m - 1) % MOD) +
                            (allWays(m - 2) % MOD) +
                            (allWays(m - 3) % MOD) +
                            (allWays(m - 4) % MOD)
                    ) % MOD;
}

LL solve(LL n, LL m, vector <LL> &dp2) {
    if (m == 0)
        return 0;
    if (m == 1)
        return 1;
    if (dp2[m] != -1)
        return dp2[m];
    LL t = (LL) pow(allWays(m), n) % MOD;
    LL tt = 0;
    for (LL i = 1; i < m; i++) {
        tt = (tt + (LL) (solve(n, i, dp2) * pow(allWays(m - i), n))) % MOD;
    }
    return dp2[m] = (t - tt + MOD) % MOD;
}

int main() {
    LL t;
    cin >> t;

    while (t--) {
        LL n, m;
        cin >> n >> m;

        vector <LL> dp2(m + 1, -1);

        cout << solve(n, m, dp2) << endl;
    }
    return 0;
}