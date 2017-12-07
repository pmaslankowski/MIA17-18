/* Zadanie: Tetris 2D
   Autor: Piotr Maślankowski
   MIA 2017/18 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
const int N = 1000000;
const int INF = 1000000000+1; 

#define DEBUG(x) cout << #x << " = " << (x) << "\n";

int maxs[4*N];
int vals[4*N];

void update(int a, int b, int val, int curr, int low, int high) {
    if ( high < a || low > b ) return;
    if (a <= low && high <= b) {
        vals[curr] = max(val, vals[curr]);
        maxs[curr] = max(maxs[curr], vals[curr]);
        return;
    }
    int mid = (low + high) / 2;
    update(a, b, val, 2*curr, low, mid);
    update(a, b, val, 2*curr+1, mid+1, high);
    maxs[curr] = max(maxs[2*curr], maxs[2*curr+1]);
}

int query(int a, int b, int curr, int low, int high) {
    if (high < a || low > b) return -INF;
    if (a <= low && high <= b)
        return maxs[curr];
    int mid = (low+high)/2;
    return max(vals[curr], max(query(a, b, 2*curr, low, mid), query(a, b, 2*curr+1, mid+1, high)));
}

int main() {
    int n, d;
    cin >> d >> n;
    for(int i=0; i < n; i++) {
        int l, x;
        cin >> l >> x;
        int curr_max_height = query(x, x+l-1, 1, 0, d-1);
        update(x, x+l-1, curr_max_height+1, 1, 0, d-1);
    }
    cout << query(0, d-1, 1, 0, d) << "\n";
    return 0;
}