#include <iostream>
#include <cmath>

int N, R;
int A[8];
bool C[8] = { false, };
int S[8];

int LIST[8];

void solve(int step = 0) {
    if (step == N) {
        int result = 0;
        
        for(int i = 1; i < N; ++i)
            result += std::abs(S[i] - S[i - 1]);
        
        if (result > R) {
            for(int i = 0; i < N; ++i)
                LIST[i] = S[i];
        }
        R = std::max(R, result);
    }
    
    for(int i = 0; i < N; ++i) {
        if (C[i] == false) {
            C[i] = true;
            S[step] = A[i];
            solve(step + 1);
            C[i] = false;
        }
    }
}

int main(int argc, const char* argv[]) {
    
    std::scanf("%d", &N);
    
    for(int i = 0; i < N; ++i)
        std::scanf("%d", A + i);
    
    solve();
    
    std::printf("%d\n", R);
    
    for(int i = 0; i < N; ++i)
        std::printf("%d ", LIST[i]);
    std::printf("\n");
    return 0;
}
