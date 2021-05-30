#include <iostream>

int f[20] = { 0, 1, };
int solve(int n) {
    if (f[n] == -1) f[n] = solve(n-2) + solve(n-1);
    return f[n];
}

int main(int argc, const char * argv[]) {
    int n;
    std::scanf("%d",&n);
    for (int i = 2; i <= n; ++i) f[i] = -1;
    std::printf("%d",solve(n));
    return 0;
}
