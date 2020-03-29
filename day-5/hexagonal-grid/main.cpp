#include <iostream>
#include <vector>
#include <utility>
#include <iterator>
#include <deque>

using namespace std;

typedef pair<int, int> pii;

int cnt = 0;

void createMap(string a, string b, vector<vector<int> > &m) {
    cnt = 0;
    for(int i = 0; i < a.size(); i++) {
        m[0][i] = a[i] == '1' ? -1 : 0;
        if(m[0][i]) {
            cnt++;
        }
    }
    for(int i = 0; i < a.size(); i++) {
        m[1][i] = b[i] == '1' ? -1 : 0;
        if(m[1][i]) {
            cnt++;
        }
    }
}

vector<pii> getAdjacent(int i, int j, vector<vector<int> > &m) {
    vector<pii> result, filteredResult;
    if(i == 0) {
        result.push_back(make_pair(i + 0, j + 1));
        result.push_back(make_pair(i + 0, j - 1));
        result.push_back(make_pair(i + 1, j - 1));
        result.push_back(make_pair(i + 1, j + 0));
    } else {
        result.push_back(make_pair(i + 0, j - 1));
        result.push_back(make_pair(i + 0, j + 1));
        result.push_back(make_pair(i - 1, j + 0));
        result.push_back(make_pair(i - 1, j + 1));
    }

    for(pii coord: result) {
        if(coord.first < 0 or coord.first >= 2) continue;
        if(coord.second < 0 or coord.second >= m[0].size()) continue;
        if(m[coord.first][coord.second] == -1) continue;
        filteredResult.push_back(coord);
    }

    return filteredResult;
}

void djikstra(pii a, pii b, string aa, string bb, vector<vector<int> > &m) {
    vector<vector<int> > m2(2, vector<int>(aa.size(), 0));
    createMap(aa, bb, m2);
    deque<pii> q;
    q.push_back(a);
    m2[a.first][a.second] = -1;
    bool flag = false;
    while(q.size() != 0) {
        pii front = q[0];
        if(front.first == b.first and front.second == b.second) {
            flag = true;
        }
        q.pop_front();

        vector<pii> adj = getAdjacent(front.first, front.second, m2);
        for(pii p: adj) {
            m2[p.first][p.second] = -1;
            q.push_back(p);
        }
    }
    if(flag) {
        m[a.first][a.second]++;
    }
}

string solve(string a, string b) {
    vector<vector<int> > m(2, vector<int>(a.size(), 0));
    createMap(a, b, m);
    if(cnt == 2 * a.size()) {
        return "YES";
    }
    if(cnt % 2 == 1) {
        return "NO";
    }

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < a.size(); j++) {
            if(m[i][j] != -1) {
                for(int p = 0; p < 2; p++) {
                    for(int q = 0; q < a.size(); q++) {
                        if(m[p][q] != -1 and !(i == p && j == q)) {
                            djikstra(make_pair(i, j), make_pair(p, q), a, b, m);
                        }
                    }
                }
            }
        }
    }

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < m[0].size(); j++) {
            if(m[i][j] != -1) {
                if(m[i][j] % 2 == 0) {
                    return "NO";
                }
            }
        }
    }
    return "YES";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        cout << solve(a, b) << endl;
    }
    return 0;
}