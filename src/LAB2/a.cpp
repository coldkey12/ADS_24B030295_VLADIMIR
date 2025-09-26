#include <iostream>

using namespace std;

int main() {

    int n;
    int target;
    int closestIndex = 0;
    cin >> n;
    int list[n];

    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }

    cin >> target;
    int closest = abs(target - list[0]);


    for (int i = 0; i < n; i++) {
        // cout << closest << " " << abs(target - list[i]) << endl;
        if (closest > abs(target - list[i])) {
            closestIndex = i;
            closest = abs(target - list[i]);
        }
    }

    cout << closestIndex << endl;

}