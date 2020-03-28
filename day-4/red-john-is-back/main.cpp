#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int isPrime(int n) {
    if(n == 2 || n == 3) {
        return true;
    }
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

int countPrimes(int n) {
    int result = 0;
    for(int i = 2; i <= n; i++) {
        if(isPrime(i)) {
            result++;
        }
    }
    return result;
}

int solve(int n) {
    if (n < 4) {
        return 1;
    }
    if (n == 4) {
        return 2;
    }
    return solve(n - 1) + solve(n - 4);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << countPrimes(solve(n)) << endl;
    }
    return 0;
}