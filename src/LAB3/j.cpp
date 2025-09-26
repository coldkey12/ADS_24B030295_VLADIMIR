#include <bits/stdc++.h>

using namespace std;

long long hoursNeeded(const vector<long long> &bags, long long k) {
    long long hours = 0;
    for (long long bars : bags) {
        hours += (bars + k - 1) / k;
        if (hours > LLONG_MAX / 2) break;
    }
    return hours;
}

int main() {

    int n;
    long long H;
    cin >> n >> H;
    vector<long long> bags(n);
    for (int i = 0; i < n; i++) cin >> bags[i];

    long long low = 1;
    long long high = *max_element(bags.begin(), bags.end());

    while (low < high) {
        long long mid = (low + high) / 2;
        if (hoursNeeded(bags, mid) <= H) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    cout << low << "\n";
    return 0;
}
