#include <iostream>
#include <algorithm>

int N;
int A[10'000];
int64_t REC[2'500];
int64_t R;

bool sorter(int a, int b) { return a > b; }

void solve() {
    int i = 0;
    int idx = 0;
    
    while(i < N - 1) {
        
        if (A[i] - A[i + 1] == 0) {
            REC[idx] = A[i];
            i += 2;
            idx += 1;
        }
        
        else if (A[i] - A[i + 1] == 1) {
            REC[idx] = A[i + 1];
            i += 2;
            idx += 1;
        }
        
        else if (A[i] - A[i + 1] > 1) {
            i += 1;
        }
    }
}

void result() {
    R = 0;
    
    int idx = 0;
    for (int i = 0; i < N/4; ++i) {
        if (REC[idx] == 0)
            break;
        
        R += (REC[idx] * REC[idx + 1]);
        idx += 2;
    }
}

int main (int argc, const char * argv []) {
    std::scanf("%d", &N);
        
    for (int i = 0; i < N; ++i) {
        std::scanf("%d", A + i);
    }
    
    std::sort(A, A + N, sorter);
    
    solve();
    result();
    
    std::printf("%lld", R);
    
    return 0;
}
