#include <iostream>
#include <vector>

using namespace std;
typedef long long LL;

LL solve(vector <LL> &h, LL n) {
    if(n == 1)
        return h[0];
    LL sum = 0;
    LL result = 0;
    LL s = 1;
    for(LL hi: h) sum += hi;
    for(LL i = 0; i < n; i++) {
        s++;
        sum -= h[i];
        result = max(result, s * sum);
    }
    return result;
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
        sort(h.begin(), h.end());
        cout << solve(h, n) << endl;
    }
    return 0;
}