#include <cstdio>
#include <cstring>


const int SIZE = 262144 + 10;
const int RANGE = 70;

int n;
int a[SIZE];
int dp[RANGE][SIZE];

#define IS_NOT_VALID(dp, i, j) ((i) == 0 || dp[(i)-1][(j)] == -1 || dp[(i)-1][dp[(i)-1][(j)]] == -1)

int main() {
    memset(a, -1, sizeof(a));
    memset(dp, -1, sizeof(dp));
    scanf("%d", &n);
    for(int i=0; i < n; i++)
        scanf("%d", &a[i]);

    int res = 0;
    for (int i = 0; i <= RANGE; i++) {
        for (int j = 0; j < n; j++) {
            if (a[j] == i) {
                dp[i][j] = j + 1;
                if(i > res) res = i;
            } else {
                if (IS_NOT_VALID(dp, i, j)) continue;
                dp[i][j] = dp[i - 1][dp[i - 1][j]];
                if(i > res) res = i;
            }
        }
    }
    printf("%d\n", res);
    return 0;
}