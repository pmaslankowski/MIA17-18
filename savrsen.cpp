/* Zadanie: SAVRSEN
   Autor: Piotr Maślankowski
   MIA 2017/18 */
#include <iostream>

using namespace std;

int a, b;
int tab[1000001];
int main() {
    cin >> a >> b;
    for(int i=1; i <= b; i++)
        tab[i] = i;
    for(int i=1; i <= b; i++)
        for(int j=2*i; j <= b; j += i)
            tab[j] -= i;
    long long result = 0;
    for(int i=a; i <= b; i++)
        if(tab[i] > 0) result += tab[i]; else result -= tab[i];
    cout << result;
    return 0;
}