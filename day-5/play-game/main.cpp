#include <iostream>
#include <vector>
#include <utility>

// NO DP

using namespace std;
typedef pair<int, int> pii;

pii solve(int i, int player, vector<int> &a) {
    if (a.size() - i < 4) {
        int score = 0;
        for (; i < a.size(); i++) {
            score += a[i];
        }
        if (player) {
            return make_pair(0, score);
        }
        return make_pair(score, 0);
    }
    pii resultA = solve(i + 1, !player, a);
    pii resultB = solve(i + 2, !player, a);
    pii resultC = solve(i + 3, !player, a);

    int scoreA = -1;
    int scoreB = -1;
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
        return make_pair(scoreA, scoreB);
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
    return make_pair(scoreA, scoreB);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << solve(0, 0, a).first << endl;
    }
    return 0;
}