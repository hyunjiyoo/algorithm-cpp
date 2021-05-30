#include <iostream>
#include <algorithm>
#include <array>

int N, M;
std::array<int, 200'000> v;

int main (int argc, const char* argv []) {
    
    std::scanf("%d %d", &N, &M);
    
    int a, b, count;
    count = N + M;
    for (int i = 0; i < N; ++i) {
        std::scanf("%d", &a);
        v[i] = a;
    }
    
    std::sort(v.begin(), v.begin() + N);
    
    for (int i = 0; i < M; ++i) {
        std::scanf("%d", &b);
        if(std::binary_search(v.begin(), v.begin() + N, b))
            count -= 2;
    }
    
    std::printf("%d", count);
    
    return 0;
}
