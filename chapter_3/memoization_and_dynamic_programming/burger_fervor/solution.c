#include <stdio.h>

int max(int v1, int v2);

void solve(int m, int n, int t);

int solve_t(int m, int n, int t);

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
    int result, i;
    result = solve_t(m, n, t);
    if (result >= 0)
        printf("%d\n", result);
    else {
        i = t - 1;
        result = solve_t(m, n, i);
        while (result == -1) {
            i--;
            result = solve_t(m, n, i);
        }
        printf("%d %d\n", result, t - i);
    }
}

int solve_t(int m, int n, int t) {
    int first, second;

    if (t == 0) return 0;
    if (t >= m) first = solve_t(m, n, t - m);
    else first = -1;

    if (t >= n) second = solve_t(m, n, t - n);
    else second = -1;

    if (first == -1 && second == -1) return -1;

    return max(first, second) + 1;
}