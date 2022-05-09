#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

#define MAX 1000


using namespace std;

vector<int> fibb;
map<int, int> pysio;

int my_version (int n);

void how_many_moves (int n);

//0 1 1 2

signed main () {
    fibb.push_back(0);
    fibb.push_back(1);

    int k;
    for (int i = 0; i < 30; i++) {
        int len = fibb.size();
        fibb.push_back(fibb[len-1] + fibb[len-2]);
    }

    how_many_moves(30);

    for (int i = 0; i < MAX; i++) {
        if (pysio[i] == 2) cout << i << " " << pysio[i] << "\n";
        //if (pysio[i] == my_version(i)) cout << "T\n";
        //else cout <<"F\n";
    }

    return 0;
}

void how_many_moves (int n) {
    for (int mask = 0; mask < (1 << n); mask++) {
        int sum = 0;
        int smiga = 1;
        for (int j = 1; j < (1 << n); j *= 2) {
            if (int(j & mask) > 0 && int((2*j) & mask) > 0) {
                smiga = 0;
                break;
            }
        }

        if (!smiga) continue;

        for (int j = 0; j < n; j++) {
            if (mask & (1 << j)) sum += fibb[j];
        }
        pysio[sum]++;
        //if (sum == 1) cout << sum << " " << mask << " " << smiga << "\n";
    }
}



int my_version (int n) {
    if (n==0)return 2;
    for (int i = 0; i < 29; i++) {
        if (n < fibb[i+1]) {
            if (n == fibb[i]) {
                if (i % 2 == 1) return 2;
                else return 3;
            }
            /*else {
                if ((n - fibb[i]) % 3 == 2 || (n-fibb[i]) % 5 == 2) return 2;
                else return 3;
            }*/

            return pysio [n-fibb[i]]; //czyli jakbym tu wywolywala rekurencyjnie to tez by smignelo, ale jak to zapisac we wzorku?
        }
    }
    throw new invalid_argument("");
}