#include <iostream>
#include <algorithm>

int N;
int A[10'000];
int64_t R;

bool sorter(int a, int b) { return a > b; }

void solve() {
    int i = 0;
    int64_t rec1 = 0;
    int64_t rec2 = 0;
    A[N] = 0;
    
    while(i < N) {
        
        if (A[i] - A[i + 1] == 0) {
            if (rec1 == 0)
                rec1 = A[i];
            else
                rec2 = A[i];
            
            i += 2;
        }
        
        else if (A[i] - A[i + 1] == 1) {
            if (rec1 == 0)
                rec1 = A[i + 1];
            else
                rec2 = A[i + 1];
            
            i += 2;
        }
        
        else if (A[i] - A[i + 1] > 1) {
            i += 1;
        }
        
        if (rec1 != 0 && rec2 != 0) {
            R += (rec1 * rec2);
            rec1 = 0;
            rec2 = 0;
        }
        
    }
}


int main (int argc, const char * argv []) {
    std::scanf("%d", &N);
        
    for (int i = 0; i < N; ++i) {
        std::scanf("%d", A + i);
    }
    
    std::sort(A, A + N, sorter);
    solve();
    std::printf("%lld", R);
    
    return 0;
}
