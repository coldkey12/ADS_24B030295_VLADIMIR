#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    long long m;
    cin >> n >> m;
    vector<long long> a(n);
    long long mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    long long lo = 1, hi = mx;
    while (lo < hi) {
        long long mid = (lo + hi) / 2;
        long long flights = 0;
        for (long long x : a) {
            flights += (x + mid - 1) / mid;
            if (flights > m) break;
        }
        if (flights <= m) hi = mid;
        else lo = mid + 1;
    }

    cout << lo << "\n";
    return 0;
}
