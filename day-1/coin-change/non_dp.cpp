// Problem : https://www.hackerrank.com/challenges/coin-change/problem
// NON_DP

#include <iostream>
#include <vector>

using namespace std;

int cc = 0;

long solve(int index, int sum, vector<long> & denominations) {
    cc++;
    if(sum == 0) return 1;
    if(sum < 0 || index == denominations.size()) return 0;
    return solve(index, sum - denominations[index], denominations)
        + solve(index + 1, sum, denominations);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<long> denominations(m);
    for(int i = 0; i < m; i++) {
        cin >> denominations[i];
    }

    cout << solve(0, n, denominations) << " " << cc << endl;
    return 0;
}