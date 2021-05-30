#include <iostream>
#include <unordered_set>

int N, M;
std::unordered_set<int> set;

int main (int argc, const char* argv []) {

    set.reserve(200'000);
    std::scanf("%d %d", &N, &M);
    
    int a, b, count;
    a = b = count = 0;
    for (int i = 0; i < N; ++i) {
        std::scanf("%d", &a);
        set.insert(a);
        ++count;
    }
    
    for (int i = 0; i < M; ++i) {
        std::scanf("%d", &b);
        ++count;
        
        if (set.count(b))
            count -= 2;
    }
    
    std::printf("%d", count);
    
    return 0;
}
