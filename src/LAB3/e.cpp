#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, k;
    cin >> n >> k;
    vector<long long> X(n), Y(n);
    long long hi = 0;
    for (int i = 0; i < n; i++) {
        long long x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        X[i] = x2;
        Y[i] = y2;
        hi = max(hi, max(x2,y2));
    }

    long long lo = 0, ans = hi;
    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (X[i] <= mid && Y[i] <= mid) cnt++;
        }
        if (cnt >= k) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << '\n';
    return 0;
}
