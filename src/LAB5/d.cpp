#include <iostream>
#include <queue>
using namespace std;
int main() {
    int n, k; cin >> n >> k;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int i = 0; i < n; i++) {
        long long x; cin >> x; pq.push(x);
    }
    int cnt = 0;
    while (pq.size() > 1 && pq.top() < k) {
        long long a = pq.top(); pq.pop();
        long long b = pq.top(); pq.pop();
        pq.push(a + 2 * b);
        cnt++;
    }
    cout << (pq.top() >= k ? cnt : -1);
}