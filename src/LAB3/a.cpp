#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;
    vector<long long> queries(t);
    for (int i = 0; i < t; i++) cin >> queries[i];

    int n, m;
    cin >> n >> m;
    vector<vector<long long>> arr(n, vector<long long>(m));
    vector<pair<long long, pair<int,int>>> values;
    values.reserve(n * m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            values.push_back({arr[i][j], {i, j}});
        }
    }

    sort(values.begin(), values.end());

    for (long long q : queries) {
        int l = 0, r = (int)values.size() - 1;
        int found = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (values[mid].first == q) {
                found = mid;
                break;
            } else if (values[mid].first < q) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if (found == -1) {
            cout << -1 << '\n';
        } else {
            cout << values[found].second.first << ' '
                 << values[found].second.second << '\n';
        }
    }

    return 0;
}
