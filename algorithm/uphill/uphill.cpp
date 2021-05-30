#include <iostream>

const int DIV = 10'007;
int N;
int DP[1'000][10];
int R;

void init() {
    R = 0;
    
    for (int i = 1; i < N; ++i)
        DP[i][0] = 1;
    
    for (int i = 0; i < 10; ++i)
        DP[0][i] = 1;

}


void solve() {
    
    for(int i = 1; i < N; ++i) {
        for (int j = 1; j < 10; ++j)
            DP[i][j] = (DP[i][j - 1] % DIV) + (DP[i - 1][j] % DIV);
    }
}


int main(int argc, const char * argv []) {
    std::scanf("%d", &N);
    
    init();
    solve();
    
    for (int i = 0; i < 10; ++i)
        R += DP[N - 1][i];
    
    
    std::printf("%d", R % DIV);
    
    return 0;
}
