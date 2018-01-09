/* Zadanie: PROMOTE
   Autor: Piotr Maślankowski
   MIA 2017/18 */

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

pair<int, int> rating[100001];
int sizes[100001];
int preorder[100001];
vector<int> child[100001];
long long tree[300100];
int result[100001];

int n;
int preorder_counter = 1;

void dfs(int current) {
    sizes[current] = 1;
    preorder[current] = preorder_counter++;
    for(int i=0; i < child[current].size(); i++) {
        dfs(child[current][i]);
        sizes[current] += sizes[child[current][i]];
    }
}

int do_query(int p, int q, int node, int a, int b) {
    if (p > b || q < a) return 0;
    if(p <= a && b <= q) return tree[node];
    int mid = (a+b)/2;
    return do_query(p, q, 2*node, a, mid) + do_query(p, q, 2*node+1, mid+1, b);
}

void do_increment(int index, int node, int a, int b) {
    if(index < a || index > b) return;    
    if(a == b) { 
        tree[node]++;
        return;
    }
    if(index <= (a+b)/2 )
        do_increment(index, 2*node, a, (a+b)/2);
    else
        do_increment(index, 2*node+1, (a+b)/2 + 1, b);
    tree[node] = tree[2*node] + tree[2*node+1];
}

int query(int p, int q) {
    return do_query(p, q, 1, 1, n);
}
void increment(int index) {
    do_increment(index, 1, 1, n);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i=1; i <= n; i++) {
        int rat;
        cin >> rat;
        rating[i] = make_pair(rat, i);
    }
    for(int i=2; i <= n; i++) {
        int node; 
        cin >> node;
        child[node].push_back(i);
    }
    
    dfs(1);
    sort(rating +1, rating + n + 1);
    for(int i=n; i >= 1; i--) {
        pair<int, int> current = rating[i];
        int node = preorder[current.second];
        result[current.second] = query(node+1, node + sizes[current.second] - 1);
        increment(node);
    }
    for(int i=1; i <= n; i++)
        cout << result[i] << "\n";

    return 0;
}