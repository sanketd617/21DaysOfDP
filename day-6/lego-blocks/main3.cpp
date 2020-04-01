#include <iostream>
#include <vector>

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

LL solve(LL n, LL m, vector<LL> &f) {
    vector <LL> g(m + 1, 0), h(m + 1, 0);
    for (LL i = 1; i <= m; i++) {
        g[i] = pow(f[i], n);
    }

    h[1] = 1;
    for (LL i = 2; i <= m; i++) {
        h[i] = g[i];
        LL t = 0;
        for (LL j = 1; j < i; j++) {
            LL tt = (h[j] * g[i - j]) % MOD;
            t = (t + tt) % MOD;
        }
        h[i] = (h[i] - t + MOD) % MOD;
    }
    return h[m];
}

int main() {
    vector <LL> f(1001, 0);
    f[0] = 1;
    for (LL i = 1; i <= 1000; i++) {
        for (LL j = 1; j <= 4; j++) {
            if (i - j >= 0) {
                f[i] = (f[i] + f[i - j]) % MOD;
            }
        }
    }

    LL t;
    cin >> t;

    while (t--) {
        LL n, m;
        cin >> n >> m;

        cout << solve(n, m, f) << endl;
    }
    return 0;
}