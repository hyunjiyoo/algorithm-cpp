#include <iostream>

int N;
int M;
int tot_cnt;
bool arrM[30];

void init() {
    tot_cnt = 0;
    for (int i = 0; i < 30; ++i) {
        arrM[i] = false;
    }
}


void solve(int step = 0, int idx = 0) {

    if (step >= N) {
        tot_cnt += 1;
        return;
    }
    
    for (int i = idx; i < M; ++i) {
        if (i > M - (N - step))
            return;
            
        arrM[i] = true;
        solve(step + 1, i + 1);
        arrM[i] = false;
    }
}


int main(int argc, const char * argv[]) {
    int T;
    std::cin >> T;
    
    for (int i = 0; i < T; ++i) {
        std::cin >> N >> M;
        
        init();
        solve();
        
        std::printf("%d\n", tot_cnt);
    }
    
    return 0;
}
