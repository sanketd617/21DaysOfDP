#include <iostream>
#include <vector>

// NO DP

using namespace std;

int solve(int k, vector<int> &a) {
    int result = 0;
    for(int ai: a) {
        if(ai > k) {
            return result;
        }
        if(ai == k) {
            return k;
        }
        result = max(result, ai + solve(k - ai, a));
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        cout << solve(k, a) << endl;
    }
    return 0;
}