/* Zadanie: Kamery
   Autor: Piotr Maślankowski
   MIA 2017/18 */

#include <iostream>
   
using namespace std;
   
char tab[1000001];
int n, k, r;
int main() {
    cin >> n >> k >> r;
    int nr;
    for(int i=0; i < k; i++) {
        cin >> nr;
        tab[nr] = 1;
    }
    int curr = 0;
    int added = 0;
    for(int i=1; i <= r-1; i++) 
        curr += tab[i];
    for(int i = r; i <= n; i++) {
        curr += -tab[i-r] + tab[i];
        if(i == r && curr == 1 && tab[i] == 1) {tab[i-1]++; curr++; added++; continue; } //bugfix
        if(curr == 1) {
            tab[i]++;
            curr++;
            added++;
        }
        if(curr == 0) {
            tab[i]++;
            tab[i-1]++;
            curr += 2;
            added += 2;
        }
    }
    cout << added;
    return 0;
}
