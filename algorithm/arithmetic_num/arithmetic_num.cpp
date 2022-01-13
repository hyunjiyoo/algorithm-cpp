#include <iostream>

int N, R;

void solve() {
    if (N < 100) {
        R = N;
        return;
    }
    
    int count = 0;
    for (int i = 100; i <= N; ++i) {
        int first = i / 100;
        int second = (i % 100) / 10;
        int third = i % 10;
        
        if ((second - first) == (third - second)) {
            ++count;
        }
    }
    
    R = 99 + count;
}

int main (int argc, const char * argv []) {
    
    std::cin >> N;
    solve();
    std::cout << R;
    
    return 0;
}
