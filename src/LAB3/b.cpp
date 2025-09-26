#include <bits/stdc++.h>

using namespace std;

bool canSplit(const vector<long long>& a, int k, long long maxSum) {
    long long current = 0;
    int blocks = 1;
    for (long long x : a) {
        if (current + x > maxSum) {
            blocks++;
            current = x;
            if (blocks > k) return false;
        } else {
            current += x;
        }
    }
    return true;
}

int main() {

    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    long long lo = 0, hi = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        lo = max(lo, a[i]);
        hi += a[i];
    }

    long long ans = hi;
    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;
        if (canSplit(a, k, mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << ans << '\n';
    return 0;
}
