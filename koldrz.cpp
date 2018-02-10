/* Zadanie: Kolorowe drzewo
   Autor: Piotr Maślankowski
   MIA 2017/18 */

#include <iostream>
#include <vector>
#include <stack>
#include <utility>
using namespace std;

int n;
vector<int> neighbors[500000];
int colors[500000];
stack<pair<int,int> > s;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    
    if (n == 0) { cout << "TAK\n"; return 0; }
    
    for(int i=1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        neighbors[a-1].push_back(b-1);
        neighbors[b-1].push_back(a-1);
    }
    for(int i=0; i < n; i++)
        cin >> colors[i];

    s.push(make_pair(0, -1));
    int root = -1;
    bool set_root_after_loop = false;
    int wrong = -1;
    while (!s.empty()) {
        pair<int, int> tmp = s.top();
        int v = tmp.first;
        int parent = tmp.second;
        s.pop();
        for(int j = 0; j < neighbors[v].size(); j++) {
            int u = neighbors[v][j];
            if(u == parent) continue;
            if(colors[v] != colors[u]) {
                if(root != -1 && v != root) { 
                    cout << "NIE\n"; 
                    return 0; 
                }
                if(wrong != -1) 
                    root = v;
                wrong = u;
            }        
            s.push(make_pair(u,v));
        }
        if(root == -1 && wrong != -1) 
            root = wrong;
    }
    cout << "TAK\n";
    return 0;
}