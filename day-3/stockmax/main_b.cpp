#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> &prices, int size) {
    int ans = 0;
    int max_price = 0;
    for (int i = size - 1; i >= 0; i--) {
        max_price = max(max_price, prices[i]);
        ans += (max_price - prices[i]);
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> prices(n);

        for (int i = 0; i < n; i++) {
            cin >> prices[i];
        }

        cout << solve(prices, n) << endl;
    }
    return 0;
}