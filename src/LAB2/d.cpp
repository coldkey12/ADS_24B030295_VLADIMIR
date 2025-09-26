#include <iostream>

using namespace std;

class Array {
    public:
    int *data;
    int size;
    Array(int n) {
        size = n;
        data =new int[n];
    }
    ~Array() {
        delete[] data;
    }
    int& operator[](int i) {
        return data[i];
    }
};

int main() {
    int n;
    cin >> n;
    Array arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Array values(n);
    Array counts(n);
    int uniqueCount = 0;

    for (int i = 0; i < n; i++) {
        int x = arr[i];
        bool found = false;
        for (int j = 0; j < uniqueCount; j++) {
            if (values[j] == x) {
                counts[j]++;
                found = true;
                break;
            }
        }
        if (!found) {
            values[uniqueCount] = x;
            counts[uniqueCount] = 1;
            uniqueCount++;
        }
    }

    int maxFreq = 0;
    for (int i = 0; i < uniqueCount; i++) {
        if (counts[i] > maxFreq) maxFreq = counts[i];
    }

    Array modes(uniqueCount);
    int modesCount = 0;
    for (int i = 0; i < uniqueCount; i++) {
        if (counts[i] == maxFreq) {
            modes[modesCount++] = values[i];
        }
    }

    for (int i = 0; i< modesCount - 1; i++) {
        for (int j = i + 1; j < modesCount; j++) {
            if (modes[i] < modes[j]) {
                int tmp = modes[i];
                modes[i] = modes[j];
                modes[j] = tmp;
            }
        }
    }

    for (int i = 0; i < modesCount; i++) {
        cout << modes[i] << (i + 1 == modesCount ? '\n' : ' ');
    }

    return 0;
}