#include <iostream>
#include <vector>

using namespace std;
typedef long long LL;

LL solve(LL s, vector <LL> &h, LL n, vector <vector<LL>> &memo) {
    if (n < 0) {
        return 0;
    }
    if (memo[s][n] != -1)
        return memo[s][n];
    LL a = solve(s + 1, h, n - 1, memo);
    LL b = h[n] * s + solve(s, h, n - 1, memo);
    return memo[s][n] = max(a, b);
}

int main() {
    LL t;
    cin >> t;

    while (t--) {
        LL n;
        cin >> n;
        vector <LL> h(n);
        vector <vector<LL>> memo(n + 2, vector<LL>(n + 2, -1));
        for (LL i = 0; i < n; i++) {
            cin >> h[i];
        }
        sort(h.begin(), h.end(), greater<LL>());
        cout << solve(1, h, n - 1, memo) << endl;
    }

}