#include <iostream>

int main (int argc, const char * argv[]) {
    
    int N;
    std::scanf("%d", &N);
    
    int cycle = 0;
    int prev = N / 10;
    int next = N % 10;
    int tmp;
    while (1) {
        
        tmp = prev;
        prev = next;
        next = (tmp + next) % 10;
        ++cycle;
        
        if (prev * 10 + next == N) {
            std::printf("%d", cycle);
            break;
        }
    }
    
    return 0;
}
