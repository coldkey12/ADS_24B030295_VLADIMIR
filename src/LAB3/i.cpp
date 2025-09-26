#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    long long x;
    cin >> x;

    int l = 0, r = n - 1;
    bool found = false;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x) {
            found = true;
            break;
        } else if (arr[mid] < x) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    if (found)
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}
