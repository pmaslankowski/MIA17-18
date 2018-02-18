/* Zadanie: Guardmark
   Autor: Piotr Maślankowski
   MIA 2017/18 */

#include<iostream>
#include<utility>

using namespace std;


const int MAX_MASK = 1050000;
int N, H;
int weight[20], height[20], strength[20];

int safety_factor[MAX_MASK];

int main() {
    ios_base::sync_with_stdio(0);

    cin >> N >> H;
    for(int i=0; i < N; i++)
        cin >> height[i] >> weight[i] >> strength[i];

    int current_max = -1;
    for(unsigned int cows = 0u; cows < (1u << N)-1; cows++)
        safety_factor[cows] = -1;
    for(unsigned int cows = 1u; cows < (1u << N)-1; cows++) {
        int cows_weight = 0;
        int cows_height = 0;
        for(int i=0; i < N; i++)
            if(cows & (1 << i)) {
                cows_weight += weight[i];
                cows_height += height[i];
            }

        for(int i=0; i < N; i++) {
            unsigned int cows_without_i = cows & ~(1 << i);
            if(cows_without_i == 0) {
                safety_factor[cows] = strength[i];
                if(height[i] >= H) 
                    current_max = max(current_max, safety_factor[cows]);
                continue;
            }
            if(cows_without_i != cows && safety_factor[cows_without_i] >= 0 && cows_weight - weight[i] <= strength[i]) {
                int new_safety_factor = min(safety_factor[cows_without_i], strength[i] - (cows_weight - weight[i]));
                safety_factor[cows] = max(safety_factor[cows], new_safety_factor);
                if(cows_height >= H)
                    current_max = max(current_max, safety_factor[cows]);
            } 
        }
    }

    if(current_max > -1)
        cout << current_max << "\n";
    else
        cout << "Mark is too tall\n";

    return 0;
}