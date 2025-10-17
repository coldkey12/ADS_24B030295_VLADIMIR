#include <iostream>
#include <queue>
using namespace std;
int main() {
    int n, m; cin >> n >> m;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        int x; cin >> x; pq.push(x);
    }
    long long ans = 0;
    for (int i = 0; i < m; i++) {
        int x = pq.top(); pq.pop();
        ans += x;
        pq.push(x - 1);
    }
    cout << ans;
}