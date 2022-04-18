#include<iostream>
#include<math.h>

using namespace std;

long long int rec (long long int n, long long int k);
int power (int a, int b);

int main () {
    for (long long int i = 1; i < 6; i++) {
        long long int a= rec (2 * (i+1), 0);
        cout << "moja " << 2*i << ": " << a << "\n";
        long long int b = pow(2, i);
        cout << 2*(i+1) << ": " << round(b*b - b - a) << "\n";
    }
}

int power (int a, int b) {
    int ret = 1;
    if (b % 2 == 1) {
        ret *= a;
        b--;
    }
    while (b > 0) {
        a *= a;
        b -= 2;
    }
    return ret * a;
}

long long int rec (long long int n, long long int k) {
    if (n == 0) {
        if (abs(k) % 8 == 4) return 1;
        else return 0;
    }
    return rec (n-1, k+1) + rec (n-1, k-1);
}