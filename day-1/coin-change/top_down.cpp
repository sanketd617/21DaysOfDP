// Problem : https://www.hackerrank.com/challenges/coin-change/problem
// TOP_DOWN

#include <iostream>
#include <vector>

using namespace std;

long solve(int index, int sum, vector<long> & denominations, vector<vector<long> > & memo) {
    if(sum == 0) return 1;
    if(sum < 0 || index == denominations.size()) return 0;

    if(memo[sum][index] != -1) {
        return memo[sum][index];
    }
    return memo[sum][index] = solve(index, sum - denominations[index], denominations, memo)
                            + solve(index + 1, sum, denominations, memo);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<long> denominations(m);
    vector<vector<long> > memo(n + 1, vector<long>(m + 1, -1));
    for(int i = 0; i < m; i++) {
        cin >> denominations[i];
    }

    cout << solve(0, n, denominations, memo) << endl;
    return 0;
}