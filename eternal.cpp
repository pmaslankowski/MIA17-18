/* Zadanie: Eternal Immortality
   Autor: Piotr Maślankowski
   MIA 2017/18 */

#include <iostream>

using namespace std;

#define PRINT_RET(x) do { cout << (x) << "\n"; return 0; } while(0);

long long a, b;

int main() {
    cin >> a >> b;
    if(b == 0) {
        switch(a) {
            case 0: case 1: PRINT_RET(1);
            case 2: PRINT_RET(2);
            case 3: PRINT_RET(6);
            case 4: PRINT_RET(4);
            default: PRINT_RET(0);
        }
    } else {
        if(b-a > 4) PRINT_RET(0);
        long long result = 1;
        for (long long i=a+1; i <= b; i++)
            result *= (i%10);

        PRINT_RET(result % 10);
    }
}