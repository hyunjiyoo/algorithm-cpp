#include <iostream>

int T;
int N;

// fibarr     fibzero   fibone
//   4     ->    2        3
//   3     ->    1        2
//   2     ->    1        1
//   1     ->    0        1
//   0     ->    1        0

bool fibarr[41] = { true, true, false, };
int fibzero[41] = { 1, 0, };
int fibone[41] = { 0, 1, };

void fib(int n) {
    if (!fibarr[n]) {
        fib(n-1);
        fib(n-2);
        
        fibzero[n] = fibzero[n-1] + fibzero[n-2];
        fibone[n] = fibone[n-1] + fibone[n-2];
        fibarr[n] = true;
    }
}


int main(int argc, const char * argv[]) {
    std::cin >> T;
    fib(40);
    for (int i = 0; i < T; ++i) {
        std::cin >> N;
        std::printf("%d %d\n", fibzero[N], fibone[N]);
    }
    
    return 0;
}
