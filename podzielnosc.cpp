/* Zadanie: Podzielnosc
   Autor: Piotr Maślankowski
   MIA 2017/18 */

#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int n;
int previous[1000000];
int val[1000000];

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n;
    queue<int> q;
    q.push(1);
    previous[1] = -1;
    while(true) {
        int l = q.front();
        q.pop();
        for(int i=0; i <= 1; i++) {
            int num = (10 * l + i) % n;
            if(num == 0) { 
                vector<int> result;
                val[num] = i;
                previous[num] = l;
                while(num != 1) {
                    int value = val[num];
                    result.push_back(value);
                    num = previous[num]; 
                } 
                cout << "1";
                for(int i=result.size() - 1; i >= 0; i--)
                    cout << result[i];
                cout << "\n";
                return 0;
            }
            else if (previous[num] == 0) {
                q.push(num);
                previous[num] = l;
                val[num] = i; 
            }
        }  
    }
    return 0;
}