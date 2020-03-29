#include <iostream>
#include <vector>

// DP

using namespace std;

int solve(int k, vector<int> &a, vector<int> &memo) {
    int result = 0;
    for(int i = 0; i < a.size(); i++) {
        int ai = a[i];
        if(ai > k) {
            return memo[k] = result;
        }
        if(ai == k) {
            return memo[k] = k;
        }
        result = max(result, ai + solve(k - ai, a, memo));
        if(result == k) {
            return memo[k] = k;
        }
    }
    return memo[k] = result;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        vector<int> memo(2001, -1);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        cout << solve(k, a, memo) << endl;
    }
    return 0;
}