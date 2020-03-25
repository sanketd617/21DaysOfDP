// Problem : https://www.hackerrank.com/challenges/coin-change/problem
// BOTTOM_UP

#include <iostream>
#include <vector>

using namespace std;

long solve(int sum, vector<long> &denominations) {
    vector <long> memo(sum + 1, 0);
    memo[0] = 1;
    for(int i = 0; i < denominations.size(); i++) {
        for(int j = denominations[i]; j < sum + 1; j++) {
            memo[j] += memo[j - denominations[i]];
        }
    }
    return memo[sum];
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<long> denominations(m);

    for (int i = 0; i < m; i++) {
        cin >> denominations[i];
    }

    cout << solve(n, denominations) << endl;
    return 0;
}