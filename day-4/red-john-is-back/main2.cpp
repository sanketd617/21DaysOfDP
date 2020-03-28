#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void calcPrimes(vector<int> &memo) {
    vector<bool> sieve(memo.size(), true);
    sieve[0] = sieve[1] = false;

    for(int i = 2; i < sqrt(memo.size()); i++) {
        if(sieve[i]) {
            for(int j = 2 * i; j < memo.size(); j += i) {
                sieve[j] = false;
            }
        }
    }
    memo[0] = memo[1] = 0;
    for(int i = 2; i < memo.size(); i++) {
        memo[i] = memo[i - 1] + sieve[i];
    }
}

int solve(int n, vector<int> &memoA) {
    if (memoA[n] != -1) {
        return memoA[n];
    }
    return memoA[n] = solve(n - 1, memoA) + solve(n - 4, memoA);
}

int main() {
    vector<int> memoA(41, -1);
    vector<int> memoB(300000, 0);
    calcPrimes(memoB);
    memoA[0] = 0;
    memoA[1] = 1;
    memoA[2] = 1;
    memoA[3] = 1;
    memoA[4] = 2;

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << memoB[solve(n, memoA)] << endl;
    }
    return 0;
}