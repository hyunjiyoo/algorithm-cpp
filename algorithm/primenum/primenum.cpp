#include <iostream>
#include <vector>

int M, N;
std::vector<bool> v;

int main (int argc, const char * argv []) {
    std::scanf("%d %d", &M, &N);
    v.resize(N + 1);
    std::fill_n(v.begin(), N + 1, true);
    v[0] = v[1] = false;
    
    for (int i = 2; i <= N; ++i) {
        if (!v[i]) continue;
        
        int j = 2;
        while (i * j <= N) {
            v[i * j++] = false;
        }
    }
    
    for (int i = M; i <= N; ++i) {
        if (v[i])
            std::printf("%d\n", i);
    }
    
    return 0;
}
