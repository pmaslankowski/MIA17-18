/* Zadanie: Ronald
   Autor: Piotr Maślankowski
   MIA 2017/18 */

#include <iostream>
#include <vector>
using namespace std;

int N, M;
int G[1000][1000];
int pattern[1000];

int main() {
    ios_base::sync_with_stdio(0);

    cin >> N >> M;
    for(int i=0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        G[a-1][b-1] = 1;
        G[b-1][a-1] = 1;
    }
    for(int i=0; i < N; i++)
        G[i][i] = 1;

    vector<int> first_clique;
    first_clique.push_back(0);
    for(int i=0; i < N; i++)
        if(G[0][i])
            first_clique.push_back(i);
    
    for(int i=0; i < first_clique.size(); i++)
        pattern[first_clique[i]] = 1;
    
    for(int i=0; i < first_clique.size(); i++) {
        int curr = first_clique[i];
        for(int j=0; j < N; j++) {
            if(G[curr][j] != pattern[j]) {
                cout << "NE\n";
                return 0;
            }
        }
    }

    vector<int> second_clique;
    for(int i=0; i < N; i++)
        if(pattern[i] == 0)
            second_clique.push_back(i);
    
    for(int i=0; i < N; i++)
        pattern[i] = 0;
    
    for(int i=0; i < second_clique.size(); i++)
        pattern[second_clique[i]] = 1;

    for(int i=0; i < second_clique.size(); i++) {
        int curr = second_clique[i];
        for(int j=0; j < N; j++) {
            if(G[curr][j] != pattern[j]) {
                cout << "NE\n";
                return 0;
            }
        }
    }

    cout << "DA\n";
    return 0;
}

