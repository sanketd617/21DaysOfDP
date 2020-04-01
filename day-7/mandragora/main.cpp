#include <iostream>
#include <vector>

using namespace std;
typedef long long LL;

LL solve(LL s, vector <LL> &h, LL n) {
    if (n < 0) {
        return 0;
    }
    LL a = solve(s + 1, h, n - 1);
    LL b = h[n] * s + solve(s, h, n - 1);
    return max(a, b);
}

int main() {
    LL t;
    cin >> t;

    while (t--) {
        LL n;
        cin >> n;
        vector <LL> h(n);
        for (LL i = 0; i < n; i++) {
            cin >> h[i];
        }
        sort(h.begin(), h.end(), greater<LL>());
        cout << solve(1, h, n - 1) << endl;
    }

}