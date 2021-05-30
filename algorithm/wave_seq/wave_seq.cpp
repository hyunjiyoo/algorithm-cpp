#include <iostream>

long long int DP[101] = { 0, 1, 1, 1, 2, 2, };

long long int solve(int n) {
    
    if (!DP[n])
        DP[n] = solve(n - 1) + solve(n - 5);
        
    return DP[n];
}

int main(int argc, const char* argv []) {
    
    int T;
    int N;
    std::scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        std::scanf("%d", &N);
        solve(N);
        
        std::printf("%lld", DP[N]);
    }
    
    return 0;
}
