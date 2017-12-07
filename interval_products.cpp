/* Zadanie: Interval products
   Autor: Piotr Maślankowski
   MIA 2017/18 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int tab[500000];
int input[100000];

void insert(int val, int index, int curr, int low, int high) {
    if(index < low || index > high) return;
    if(low == high) {
        tab[curr] = val;
        return;
    }
    int mid = (low+high)/2;
    insert(val, index, 2*curr, low, mid);
    insert(val, index, 2*curr+1, mid + 1, high);
    tab[curr] = tab[2*curr] * tab[2*curr+1]; 
}

int product(int curr, int low, int high, int a, int b) {
    if(a > high || b < low) return 1;
    if(a <= low && b >= high) return tab[curr];
    int mid = (low+high)/2;
    return product(2*curr, low, mid, a, b) * product(2*curr+1, mid+1, high, a, b);
}

void build(int curr, int low, int high) {
    if(low == high) {
        tab[curr] = input[low];
        return;
    }
    int mid = (low+high)/2;
    build(2*curr, low, mid);
    build(2*curr+1, mid+1, high);
    tab[curr] = tab[2*curr] * tab[2*curr+1];
}

/*void print() {
    cout << "STATE:\n";
    for(int i=0; i <= 2*SIZE-1; i++) {
        cout << tab[i] << " ";
    }
    cout << "\n";
}*/

int main() {
    int n, k;
    while(cin >> n >> k){
        for(int i=0; i < n; i++) {
            cin >> input[i];
            if (input[i] > 0) input[i] = 1;
            if (input[i] < 0) input[i] = -1;
        }
        build(1, 0, n-1);
        for(int j=0; j < k; j++) {
            char what;
            cin >> what;
            if(what == 'C') {
                int i, v;
                cin >> i >> v;
                i--;
                if(v > 0) v = 1;
                if(v < 0) v = -1;
                insert(v, i, 1, 0, n-1);
                input[i] = v;
            }
            if(what == 'P') {
                int a, b;
                cin >> a >> b;
                a--; b--;
                int res = product(1, 0, n-1, a,b);
                if(res > 0) cout << "+";
                if(res == 0) cout << "0";
                if(res < 0) cout << "-";
                //cout << res;
            }
            //print();
        }
        cout << "\n";
    }
    return 0;
}
