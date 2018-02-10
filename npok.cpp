/* MIA 2017/18
   NPOK
   Autor: Piotr Maślankowski */

#include <iostream>

using namespace std;

int n, k, p, t;
long long nom, denom;

int pow(int x, int k, int p) {
    long long res = 1;
    long long curr = x;
    while (k >= 1) {
        if (k % 2 == 1) res = (res * (curr % p)) % p;
        curr = (curr * curr) % p;
        k /= 2; 
    }
    return res;
}

int main() {
    cin >> t;
    for(int test = 0; test < t; test++) {
        cin >> n >> k >> p;
        if(k == 0) {
            cout << 1 << "\n";
            continue;
        }
        nom = n;
        denom = k % p;
        for(int i=1; i < k; i++) {
            nom = (nom * (n-i)) % p;
            denom = (denom * i) % p; 
        }
        cout << (nom * pow(denom, p-2, p)) % p << "\n";
    }
    return 0;
}