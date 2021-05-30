#include <iostream>

int C;
int N;
bool fibarr[40] = { true, true, };
int zero_cnt;
int one_cnt;

void fib(int n) {
    
    if (fibarr[n]) {
        if (n == 0) {
            zero_cnt += 1;
            return;
        }
        
        if (n == 1) {
            one_cnt += 1;
            return;
        }
    }
    
    fib(n-1);
    fib(n-2);
    fibarr[n] = true;

}

int main(int argc, const char * argv[]) {
    std::cin >> C;
    
    for (int i = 0; i < C; ++i) {
        std::cin >> N;
        
        zero_cnt = 0;
        one_cnt = 0;
        
        fib(N);
        
        std::printf("%d %d\n", zero_cnt, one_cnt);
    }
    
    return 0;
}
