#include <iostream>
#include <vector>
#include <utility>

// DP

using namespace std;
typedef long long LL;
typedef pair<LL, LL> pll;

pll solve(LL i, LL player, vector<LL> &a, vector<vector<pll > > &memo) {
    if(memo[i][player].first != -1) {
        return memo[i][player];
    }
    if (a.size() - i < 4) {
        LL score = 0;
        for (; i < a.size(); i++) {
            score += a[i];
        }
        if (player) {
            return make_pair(0, score);
        }
        return  make_pair(score, 0);
    }
    pll resultA = solve(i + 1, !player, a, memo);
    pll resultB = solve(i + 2, !player, a, memo);
    pll resultC = solve(i + 3, !player, a, memo);

    LL scoreA = -1;
    LL scoreB = -1;
    if(!player) {
        if(resultA.first + a[i] > scoreA) {
            scoreA = resultA.first + a[i];
            scoreB = resultA.second;
        }
        if(resultB.first + a[i] + a[i + 1] > scoreA) {
            scoreA = resultB.first + a[i] + a[i + 1];
            scoreB = resultB.second;
        }
        if(resultC.first + a[i] + a[i + 1] + a[i + 2] > scoreA) {
            scoreA = resultC.first + a[i] + a[i + 1] + a[i + 2];
            scoreB = resultC.second;
        }
        return memo[i][player] = make_pair(scoreA, scoreB);
    }
    if(resultA.second + a[i] > scoreB) {
        scoreA = resultA.first;
        scoreB = resultA.second + a[i];
    }
    if(resultB.second + a[i] + a[i + 1] > scoreB) {
        scoreA = resultB.first;
        scoreB = resultB.second + a[i] + a[i + 1];
    }
    if(resultC.second + a[i] + a[i + 1] + a[i + 2] > scoreB) {
        scoreA = resultC.first;
        scoreB = resultC.second + a[i] + a[i + 1] + a[i + 2];
    }
    return memo[i][player] = make_pair(scoreA, scoreB);
}

int main() {
    LL t;
    cin >> t;
    while (t--) {
        LL n;
        cin >> n;
        vector<LL> a(n);
        vector<vector<pll > > memo(n, vector<pll >(2, make_pair(-1, -1)));
        for (LL i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << solve(0, 0, a, memo).first << endl;
    }
    return 0;
}