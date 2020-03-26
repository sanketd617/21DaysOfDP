#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int maxSubArraySum(vector<int> & array, int size) {
    int max_sub_array_sum = -INT_MAX;
    int temp = 0;
    for (int i = 0; i < size; ++i) {
        temp = max(temp + array[i], array[i]);
        max_sub_array_sum = max(max_sub_array_sum, temp);
    }
    return max_sub_array_sum;
}

int maxSubSeqSum(vector<int> & array, int size) {
    int max_sub_seq_sum = 0;
    int maximum = -INT_MAX;
    bool flag = false;
    for(auto x: array) {
        if(x >= 0) {
            flag = true;
            max_sub_seq_sum += x;
        }
        maximum = max(maximum, x);
    }

    return flag ? max_sub_seq_sum : maximum;
}

vector<int> solve(vector<int> & array, int size) {
    vector<int> ans;
    ans.push_back(maxSubArraySum(array, size));
    ans.push_back(maxSubSeqSum(array, size));
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> array(n);

        for(int i = 0; i < n; i++) {
            cin >> array[i];
        }

        vector<int> solution = solve(array, n);

        for(auto x: solution) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}