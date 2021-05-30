#include <iostream>
#include <algorithm>

int N, R;
int S[10'001];
int W[10'001][3];

int n;
int wine[10'000];
int DP[10'000][3];
int result = -1;
int ret = -1;

void solve() {
    W[1][0] = 0;
    W[1][1] = S[1];
    W[1][2] = 0;
    
    for(int i = 2; i <= N; ++i) {
        W[i][0] = std::max({ W[i - 1][0], W[i - 1][2], W[i - 1][1] });
        W[i][1] = W[i - 1][0] + S[i];
        W[i][2] = W[i - 1][1] + S[i];
    }
    
    R = std::max({ W[N][0], W[N][1], W[N][2] });
}

void solve2() {
    ret = DP[1][2];
    
    for (int i = 2; i < n; ++i) {
        DP[i][1] = std::max(DP[i-2][1], DP[i-2][2]) + wine[i];
        DP[i][2] = DP[i-1][1] + wine[i];
        
        result = std::max(DP[i][1], DP[i][2]);
        ret = std::max(ret, result);
    }
}

void input() {
    n = N = rand() % 6 + 1;
    for(int i = 0; i < n; ++i) {
        S[i + 1] = wine[i] = rand() % 20;
    }
}

int main(int argc, const char* argv[]) {
    while(true) {
        input();
        result = -1;
        ret = -1;
        R = 0;
        
        
        DP[0][1] = wine[0];
        DP[0][2] = 0;
        DP[1][1] = wine[1];
        DP[1][2] = wine[0] + wine[1];
        
        solve();
        
        if (n == 1)
            ret = wine[0];
        
        else if (n == 2)
            ret = wine[0] + wine[1];
        
        else
            solve2();
            
        if (R != ret) {
            
        }
    }
    
    return 0;
}
