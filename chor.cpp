/* Zadanie: Choosing recipes
   Autor: Piotr Maślankowski
   MIA 2017/18 */

#include <iostream>

using namespace std;

const int INF = 1000001;

int Q, R, P, N, M;
bool start_ingredients[13];
int cost[13];
bool Mat[30][13];

typedef unsigned int mask_t;

int main() {
    ios_base::sync_with_stdio(0);

    cin >> Q;
    for(int query = 0; query < Q; query++) {
        cin >> R >> P >> N >> M;
        for(int i=0; i < 13; i++)
            start_ingredients[i] = false;
        for(int i=0; i < 13; i++)
            cost[i] = 0;
        for(int i=0; i < 30; i++)
            for(int j=0; j < 13; j++)
                Mat[i][j] = false;

        for(int i=0; i < M; i++) {
            int tmp;
            cin >> tmp;
            start_ingredients[tmp] = true;
        }
        for(int i=0; i < P; i++)
            cin >> cost[i];
        for(int i=0; i < R; i++)
            for(int j=0; j < P; j++)
                cin >> Mat[i][j];

        int min_cost = INF;
        for(mask_t mask=0; mask < (1u << P); mask++) {
            int current_cost = 0;
            for(int i=0; i < P; i++)
                if(mask & (1 << i) && !start_ingredients[i])
                    current_cost += cost[i];
            
            int possible_recipes = 0;
            for(int i=0; i < R; i++) {
                int possible = 1;
                for(int j=0; j < P; j++)
                    if(Mat[i][j] && ((mask & (1 << j)) == 0)) {
                        possible = 0;
                        break;
                    }
                possible_recipes += possible;
            }

            if(possible_recipes >= N && current_cost < min_cost)
                min_cost = current_cost;
        } 
        cout << min_cost << "\n";  
    }

    return 0;
}