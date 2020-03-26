// Problem : https://www.hackerrank.com/challenges/manasa-and-stones/problem
// NON_DP

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

void solve(int val, int level, int n, int a, int b, unordered_set<int> &ans) {
    if(a == b) {
        ans.insert(a * (n-1));
        return;
    }
    if(level == n - 1) {
        ans.insert(val);
        return;
    }
    solve(val + a, level + 1, n, a, b, ans);
    solve(val + b, level + 1, n, a, b, ans);
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, a, b;
        cin >> n >> a >> b;
        unordered_set<int> solution;
        vector<int> solutionVector;
        solve(a, 1, n, a, b, solution);
        solve(b, 1, n, a, b, solution);
        solutionVector.insert(solutionVector.end(), solution.begin(), solution.end());
        sort(solutionVector.begin(), solutionVector.end());
        for(auto x: solutionVector) {
            cout << x << " ";
        }
        cout << endl;
    }
}