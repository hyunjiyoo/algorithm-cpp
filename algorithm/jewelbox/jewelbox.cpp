#include <iostream>
#include <limits>

int N, M, max;
int jewel[300'000];

void input() {
    std::scanf("%d %d", &N, &M);
    
    max = std::numeric_limits<int>::min();
    for (int i = 0; i < M; ++i) {
        std::scanf("%d", jewel + i);
        if (max < jewel[i])
            max = jewel[i];
    }
}


void solve() {
    
    int low = 1;
    int high = max;
    
    while (high > low + 1) {
        int mid = (low + high) / 2;
        
        int count = 0;
        for (int i = 0; i < M; ++i) {
            int add = (jewel[i] - 1) / mid + 1;
            count += add;
            
            if (count > N) break;
        }
        
        if (count <= N)
            high = mid;
        else
            low = mid;
    }
 
    std::printf("%d", high);
}


int main (int argc, const char * argv []) {
    
    input();
    solve();
    
    return 0;
}
