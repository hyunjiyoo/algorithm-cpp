#include <iostream>

int N;
int dw[1'000][2];
int DONE[1'000];
int R;

void init() {
    R = 0;
    for (int i = 0; i < 1'000; ++i) {
        dw[i][0] = 0;
        dw[i][1] = 0;
        DONE[i] = 0;
    }
}


void sort() {
    int tmp0 = 0;
    int tmp1 = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (dw[i][1] > dw[j][1]) {
                tmp0 = dw[i][0];
                tmp1 = dw[i][1];
                dw[i][0] = dw[j][0];
                dw[i][1] = dw[j][1];
                dw[j][0] = tmp0;
                dw[j][1] = tmp1;
            }
            
        }
    }
}


void solve() {
    
    int idx = 0;
    int d = 0;
    int w = 0;
    for (int i = 0; i < N; ++i) {
        d = dw[i][0];
        w = dw[i][1];
        
        idx = d - 1;
        
        if (!DONE[idx]) {
            DONE[idx] = w;
        
        } else {
        
            for (int j = idx; j >= 0; --j) {
                if (!DONE[j]) {
                    DONE[j] = w;
                    break;
                }
            }
        }
    }
    
}



int main (int argc, const char * argv []) {
    init();
    
    std::scanf("%d", &N);

    for (int i = 0; i < N; ++i) {
        std::scanf("%d %d", &dw[i][0], &dw[i][1]);
    }
    
    sort();
    solve();
    
    for (int i = 0; i < 1'000; ++i) {
        R += DONE[i];
    }
    
    std::printf("%d", R);
    
    return 0;
}
