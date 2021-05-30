#include <iostream>
#include <stack>

int main (int argc, const char * argv []) {
    int K, n;
    std::stack<int> s;
    std::scanf("%d", &K);
    
    for (int i = 0; i < K; ++i) {
        std::scanf("%d", &n);
        if (n != 0)
            s.push(n);
        else
            s.pop();
    }

    int64_t R = 0;
    while(!s.empty()) {
        R += s.top();
        s.pop();
    }
    
    std::printf("%lld", R);
    
    return 0;
}
