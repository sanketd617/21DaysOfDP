#include <iostream>
#include <cmath>

using namespace std;

#define MOD 1000000007

typedef long long LL;

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
    if(m < 0) return 0;
    if(m == 0) return 1;
    return (
                   (allWays(m - 1) % MOD) +
                   (allWays(m - 2) % MOD) +
                   (allWays(m - 3) % MOD) +
                   (allWays(m - 4) % MOD)
           ) % MOD;
}

LL solve(LL n, LL m) {
    if(m == 0)
        return 0;
    if(m == 1)
        return 1;
    LL t = (LL)pow(allWays(m), n) % MOD;
    LL tt = 0;
    for(LL i = 1; i < m; i++) {
        tt = (tt + (LL)(solve(n, i) * pow(allWays(m - i), n))) % MOD;
    }
    return (t - tt + MOD) % MOD;
}

int main() {
    LL t;
    cin >> t;

    while (t--) {
        LL n, m;
        cin >> n >> m;

        cout << solve(n, m) << endl;
    }
    return 0;
}