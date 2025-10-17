#include <iostream>
#include <queue>
#include <string>
using namespace std;
int main() {
    int q, k; cin >> q >> k;
    priority_queue<int, vector<int>, greater<int>> pq;
    long long sum = 0;
    while (q--) {
        string cmd; cin >> cmd;
        if (cmd == "insert") {
            int x; cin >> x;
            pq.push(x);
            sum += x;
            if ((int)pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
        } else cout << sum << endl;
    }
}