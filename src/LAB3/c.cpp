#include <iostream>

using namespace std;

long long countInRange(const vector<long long>& A, long long l, long long r) {
    long long cnt = 0;
    for (long long x : A) {
        if (x >= l && x <= r) cnt++;
    }
    return cnt;
}


int main() {
    int n, q;
    cin >> n >> q;
    vector<long long> A(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    while(q--) {
        long long l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        auto c1 = countInRange(A, l1, r1);
        auto c2 = countInRange(A, l2, r2);

        long long L = max(l1, l2);
        long long R = min(r1, r2);
        long long c0verlap = 0;

        if (L <= R) {
            c0verlap = countInRange(A, max(l1,l2), min(r1,r2));
        }

        cout << (c1 + c2 - c0verlap) << '\n';
    }
}