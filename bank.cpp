/* Zadanie: Bankier
   Autor: Piotr Maślankowski
   MIA 2017/18 */

#include<iostream>
#include<stack>
#include<queue>
#include<vector>

using namespace std;

int T;
int n;
long long int S;

int envelopes_to_delete[1000010]; // lazy deletion from priority queue

int main() {
    ios_base::sync_with_stdio(0);

    cin >> T;
    for(int test=0; test < T; test++) {
        cin >> n >> S;
        stack<int> envelopes;
        priority_queue<int, vector<int>, greater<int> > q; // max priority queue
        for(int i=0; i < 1000010; i++)
            envelopes_to_delete[i] = 0;
            
        for(int i=0; i < n; i++) {
            int amount;
            cin >> amount;
            if(amount > 0) {
                envelopes.push(amount);
                q.push(amount);
            } else {
                if (envelopes.empty() || -amount < q.top())
                    S += amount;
                else {
                    while(amount < 0 && !envelopes.empty()) {
                        amount += envelopes.top();
                        envelopes_to_delete[envelopes.top()]++;
                        envelopes.pop();
                    }
                    S += amount;
                    while(!q.empty() && envelopes_to_delete[q.top()] > 0) {
                        envelopes_to_delete[q.top()]--;
                        q.pop();
                    }
                }
            }
        }

        long long int env = 0;
        while(!envelopes.empty()) {
            env += envelopes.top();
            envelopes.pop();
        }
        cout << S << " " << env << "\n";

    }

    return 0;
}