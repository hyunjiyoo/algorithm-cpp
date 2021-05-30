#include <iostream>
#include <algorithm>
#include <vector>

int N, M;
std::vector<int> v;

int main (int argc, const char* argv []) {
    
    v.reserve(200'000);
    std::scanf("%d %d", &N, &M);
    
    int a, b, count;
    count = N + M;
    for (int i = 0; i < N; ++i) {
        std::scanf("%d", &a);
        v.push_back(a);
    }
    
    std::sort(v.begin(), v.end());
    
    for (int i = 0; i < M; ++i) {
        std::scanf("%d", &b);
        if(std::binary_search(v.begin(), v.end(), b))
            count -= 2;
    }
    
    std::printf("%d", count);
    
    return 0;
}
