#include <iostream>
using namespace std;
#define PI 3.14159

double area(double radius) {
    return PI * radius * radius;
}
int area(int length, int breadth) {
    return length * breadth;
}
double area(double base, double height, bool isTriangle) {
    return 0.5 * base * height;
}

int main() {
    double radius;
    int length, breadth;
    double base, height;

    cin >> radius;
    cin >> length >> breadth;
    cin >> base >> height;

    cout.precision(5);
    cout << fixed;
    cout << area(radius) << endl;
    cout << area(length, breadth) << endl;
    cout << area(base, height, true) << endl;

    return 0;
}
