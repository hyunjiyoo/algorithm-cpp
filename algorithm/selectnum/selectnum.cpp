#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>

int N, M, R;
std::vector<int> seq;

void input() {
    std::scanf("%d %d", &N, &M);
    seq.resize(N);
    for (int i = 0; i < N; ++i)
        std::scanf("%d", &seq[i]);
    
    std::sort(seq.begin(), seq.end());
}

void solve() {
    R = std::numeric_limits<int>::max();
    
    int lptr = 0, rptr = 1;
    
    while (true) {
        if (lptr == N)
            break;
        
        int diff = seq[rptr] - seq[lptr];
        
        if (diff < M) { // inc
            while (diff < M && rptr < N)
                diff = seq[++rptr] - seq[lptr];
        } else { // dec
            while (diff > M && rptr > lptr)
                diff = seq[--rptr] - seq[lptr];
            diff = seq[++rptr] - seq[lptr];
        }
        
        if (diff >= M)
            R = std::min(R, diff);
        
        ++lptr;
    }
}

int main (int argc, const char * argv []) {
    
    input();
    solve();
    std::printf("%d", R);
    
    return 0;
}
