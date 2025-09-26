#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, m;
    cin >> n >> m;
    vector<long long> a(n), pref(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pref[i] = a[i] + (i > 0 ? pref[i-1] : 0);
    }

    for (int j = 0; j < m; j++) {
        long long x;
        cin >> x;
        int idx = lower_bound(pref.begin(), pref.end(), x) - pref.begin();
        cout << idx + 1 << "\n";
    }
    return 0;
}
