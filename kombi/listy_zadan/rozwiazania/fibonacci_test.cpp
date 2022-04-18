#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

int fibonacci (int n);
int dwumian (int n, int k);
int sum (int n, int k);
double recur (int n);

vector<double> results;

int main () {
    for (int i = 1; i < 31; i++) {
        //cout << fibonacci (i) << "\n";
        //cout << j << " nad " << i << ": " << dwumian (j, i) << "\n";
        //cout << sum (i, i+1) << "\n";
        results.push_back(recur(i));
        cout << i << ": " << results[i-1] << "\n";
        //recur (i);
    }
    return 0;
}

double recur (int n) {
    if (n == 1) return 1;
    if (n == 2) return 1;

    double s = 1 - sum (n, n+1);
    double d = recur (n-1);
    double rek = 2+ceil(abs(results[n-2]-results[n-3])/2-floor(1/results[n-3]));
    double ret = s * rek;
    ret += sum (n, n+1) + floor(4/n);
    return ret;
}

int fibonacci (int n) {
    if (n == 0) return 0;
    int ret = 1;
    int prev = 1;
    int prevprev = 0;

    n -= 2;

    while (n > 0) {
        ret += prev;
        int pom = prev;
        prev += prevprev;
        prevprev = pom;
        n--;
    }

    return ret;
}

int dwumian (int n, int k) {
    if (k == 0) return 1;
    if (k > n) return 0;
    return (n * dwumian (n-1, k-1)) / k;
}

int sum (int n, int k) {
    int ret = 0;
    while (k >= 0) {
        int fib_k = fibonacci (k);
        ret += dwumian (n, fib_k) * dwumian (fib_k, n);
        k--;
    }
    return ret;
}