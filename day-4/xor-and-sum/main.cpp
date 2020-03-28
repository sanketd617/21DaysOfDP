#include <iostream>
#include <vector>

#define MAX 314159
#define MOD 1000000007

using namespace std;

long long expMod(long long i) {
    long long x = 2;
    long long result = 1;
    while (i > 0) {
        if (i & 1) {
            result = (result * x) % MOD;
        }
        i = i >> 1;
        x = (x * x) % MOD;
    }
    return result;
}

long long decimalMod(vector<long long> &result) {
    long long ans = 0;
    for (long long i = 0; i < result.size(); i++) {
        ans = (ans + expMod(i) * result[i]) % MOD;
    }
    return ans;
}

void padZeroesAndRev(string &a, string &b) {
    long long size = max(a.size(), b.size());
    long long aSize = a.size();
    long long bSize = b.size();
    for (long long i = 0; i < size - aSize; i++) {
        a = '0' + a;
    }
    for (long long i = 0; i < size - bSize; i++) {
        b = '0' + b;
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
}

long long getCarryAndSetResult(long long numOnes, vector<long long> &result) {
    result.push_back(numOnes % 2);
    return numOnes / 2;
}

void countOnes(string b, vector<long long> &ones, vector<long long> &onesRev) {
    ones[0] = b[0] == '1';
    onesRev[b.size() - 1] = b[b.size() - 1] == '1';

    for (long long i = 1; i < b.size(); i++) {
        ones[i] = ones[i - 1] + (b[i] == '1');
    }

    for (long long i = b.size() - 2; i >= 0; i--) {
        onesRev[i] = onesRev[i + 1] + (b[i] == '1');
    }
}

long long solve(string a, string b) {
    padZeroesAndRev(a, b);
    vector<long long> ones(b.size(), 0), onesRev(b.size(), 0), result;
    countOnes(b, ones, onesRev);

    long long carry = 0;
    long long i = 0;
    for (; i < a.size(); i++) {
        long long n = 0;
        long long zeroes = 0;
        if (a[i] == '0') {
            n = ones[i] + carry;
        } else {
            zeroes = i + 1 - ones[i];
            n = MAX + carry + zeroes - i;
        }
        carry = getCarryAndSetResult(n, result);
    }

    for (; i < MAX; i++) {
        long long n = ones[a.size() - 1] + carry;
        carry = getCarryAndSetResult(n, result);
    }

    for (; i < MAX + b.size(); i++) {
        long long n = onesRev[i - MAX] + carry;
        carry = getCarryAndSetResult(n, result);
    }


    while (carry != 0) {
        result.push_back(carry % 2);
        carry = carry / 2;
    }

    return decimalMod(result);
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << solve(a, b) << endl;
    return 0;
}