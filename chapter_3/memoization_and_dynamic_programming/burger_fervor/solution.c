#include <stdio.h>

#define SIZE 10000

int max(int v1, int v2);

void solve(int m, int n, int t);

int main() {
    int m, n, t;
    while (scanf("%d%d%d", &m, &n, &t) != -1)
        solve(m, n, t);
    return 0;
}

int max(int v1, int v2) {
    return v1 > v2 ? v1 : v2;
}

void solve(int m, int n, int t) {
    int result, i, first, second;
    int dp[SIZE];
    dp[0] = 0;

    for (i = 1; i <= t; ++i) {
        if (i >= m) first = dp[i - m];
        else first = -1;

        if (i >= n) second = dp[i - n];
        else second = -1;

        if (first == -1 && second == -1)
            dp[i] = -1;
        else
            dp[i] = max(first, second) + 1;
    }

    result = dp[t];
    if (result >= 0) printf("%d\n", result);
    else {
        i = t - 1;
        result = dp[i];
        while (result == -1) {
            i--;
            result = dp[i];
        }
        printf("%d %d\n", result, t - i);
    }
}
