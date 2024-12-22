#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n == 0) {
        cout << 1 << endl;
        return 0;
    }

    int count = 0;
    n = abs(n); // Handle negative numbers

    while (n > 0) {
        n /= 10;
        count++;
    }

    cout << count << endl;
    return 0;
} 
