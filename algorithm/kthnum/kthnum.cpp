#include <iostream>
#include <vector>
#include <algorithm>

int N, K;
std::vector<int> v;

int main (int argc, const char * argv []) {
    
    std::scanf("%d %d", &N, &K);
    v.resize(N);
    for (int i = 0; i < N; ++i) {
        std::scanf("%d", &v[i]);
    }
    
    std::sort(v.begin(), v.end());
    std::printf("%d", v[K - 1]);
    
    return 0;
}
