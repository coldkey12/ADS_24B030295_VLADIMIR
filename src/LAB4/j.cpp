#include <bits/stdc++.h>
using namespace std;

void buildBalanced(vector<int>& arr, int left, int right, vector<int>& result) {
    if (left > right) return;

    int mid = left + (right - left) / 2;
    result.push_back(arr[mid]);

    buildBalanced(arr, left, mid - 1, result);
    buildBalanced(arr, mid + 1, right, result);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> k;

    int n = (1 << k) - 1;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    vector<int> result;
    buildBalanced(arr, 0, n - 1, result);

    for (int i = 0; i < n; i++) {
        if (i > 0) cout << " ";
        cout << result[i];
    }
    cout << "\n";

    return 0;
}