#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, q;
    cin >> n >> q;
    vector<long long> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];

    sort(A.begin(), A.end());

    while (q--) {
        long long l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        auto c1 = upper_bound(A.begin(), A.end(), r1)
                - lower_bound(A.begin(), A.end(), l1);
        auto c2 = upper_bound(A.begin(), A.end(), r2)
                - lower_bound(A.begin(), A.end(), l2);

        long long L = max(l1, l2);
        long long R = min(r1, r2);
        long long cOverlap = 0;
        if (L <= R) {
            cOverlap = upper_bound(A.begin(), A.end(), R)
                     - lower_bound(A.begin(), A.end(), L);
        }

        cout << (c1 + c2 - cOverlap) << '\n';
    }

    return 0;
}
