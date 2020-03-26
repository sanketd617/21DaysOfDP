// Problem : https://www.hackerrank.com/challenges/manasa-and-stones/problem
// BOTTOM_UP_DP

#include <iostream>
#include <vector>

using namespace std;

vector<int> solve(int n, int a, int b) {
    int diff = abs(a - b);
    vector<int> result(n);
    result[0] = (n - 1) * min(a, b);

    if(a == b)  return vector<int>(1, result[0]);

    for(int i = 1; i < n; i++) {
        result[i] = (result[0] + i * diff);
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, a, b;
        cin >> n >> a >> b;
        vector<int> solution = solve(n, a, b);
        for(auto x: solution) {
            cout << x << " ";
        }
        cout << endl;
    }
}