#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    long long S;
    cin >> n >> S;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    long long sum = 0;
    int left = 0;
    int minLen = n + 1;

    for (int right = 0; right < n; right++) {
        sum += a[right];
        while (sum >= S) {
            minLen = min(minLen, right - left + 1);
            sum -= a[left];
            left++;
        }
    }

    cout << minLen << "\n";
    return 0;
}
