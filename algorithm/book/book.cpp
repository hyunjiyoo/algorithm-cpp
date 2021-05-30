#include <iostream>
#include <algorithm>

int N, M;
int STD[1'000][2];
int* PSTD[1'000];
bool POSSIBLE[1'000];
int R;

void init() {
    R = 0;
    
    for (int i = 0; i < 1'000; ++i) {
        POSSIBLE[i] = false;
        STD[i][0] = 0;
        STD[i][1] = 0;
        PSTD[i] = STD[i];
    }
}


void input() {
    std::scanf("%d %d", &N, &M);
    
    for (int i = 0; i < M; ++i)
        std::scanf("%d %d", &STD[i][0], &STD[i][1]);
}


void solve() {
    
    std::sort(PSTD, PSTD + M, [](auto a, auto b) {
        return a[1] < b[1];
    });
    
    for (int i = 0; i < M; ++i) {
        for (int j = PSTD[i][0] - 1; j < PSTD[i][1]; ++j) {
            if (POSSIBLE[j]) {
                continue;
                
            } else {
                POSSIBLE[j] = true;
                R += 1;
                break;
            }
        }
    }
}


int main (int argc, const char * argv []) {
    int C;
    std::scanf("%d", &C);
    
    for (int i = 0; i < C; ++i) {
        
        init();
        input();
        solve();
        std::printf("%d\n", R);
    }
    
    return 0;
}
