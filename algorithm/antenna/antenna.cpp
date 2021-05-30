#include <iostream>
#include <algorithm>

int N;
int HOME[200'001];
int R;

bool sorter (int a, int b) { return a > b; }

void solve() {
    
    if (N % 2 != 0) {
        
        R = HOME[N/2];
        
    } else {
        
        int diff1 = 0;
        int diff2 = 0;
        int accum1 = 0;
        int accum2 = 0;
        
        for (int i = 0; i < N; ++i) {
            diff1 = HOME[(N/2)-1] - HOME[i];
            diff2 = HOME[N/2] - HOME[i];
            if (diff1 < 0)
                diff1 *= (-1);
            
            if (diff2 < 0)
                diff2 *= (-1);
                
            accum1 += diff1;
            accum2 += diff2;
        }
        
        if (accum1 < accum2)
            R = HOME[(N/2)-1];
        else
            R = HOME[N/2];
    }
    
    return;
}


int main (int argc, const char * argv []) {
    
    std::scanf("%d", &N);
    for (int i = 0; i < N; ++i)
        std::scanf("%d", HOME + i);
    
    std::sort(HOME, HOME + N, sorter);
    solve();
    
    std::printf("%d", R);
    
    return 0;
}
