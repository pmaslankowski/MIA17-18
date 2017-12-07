/* Zadanie: Alfabet
   Autor: Piotr Maślankowski
   MIA 2017/18 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int INF = 256;
int dp[51];
string s;

int main() {
    cin >> s;
    for(int i=0; i < s.size(); i++)
        dp[i] = INF;
    for(int i=0; i < s.size(); i++) {
        int j = 0;
        while (j < s.size() && dp[j] < s[i])
            j++;
        dp[j] = s[i];
    }
    int i=s.size() - 1;
    while(i >= 0 && dp[i] == INF)
        i--;
    cout << 26 - (i+1) << "\n";
    return 0;
}
