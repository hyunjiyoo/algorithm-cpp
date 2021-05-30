#include <iostream>

int N;
int DP[100'001];
int R;


void print() {
    for (int i = 0; i <= N; ++i) {
        std::cout << DP[i] << ' ';
    }
    std::cout << std::endl;
}

void init() {
    
    R = 0;
    
    for (int i = 0; i <= N; ++i)
        DP[i] = 0;
    
    DP[0] = 1;
    DP[1] = N * 2;
    for (int i = N; i > 1; --i) {
        DP[2] += (2 * i - 3) * 2;
    }
    
    DP[N] = 2;
}

void solve(int n) {
//    print();
    
    if (!DP[n - 1]) {
        int sum1 = 0;
        int sum2 = 0;
        
        for (int i = n; (2 * i - 5) > 0; --i) {
            sum1 += (2 * i - 5) * 2;
        }
        
        for (int i = n; (2 * i - 7) > 0; --i) {
            sum2 += (2 * i - 7) * 4;
        }
        
        DP[n - 1] = sum1 + sum2;
        
        solve(n - 1);
        std::cout << "sum1 : " << sum1 << std::endl;
        std::cout << "sum2 : " << sum2 << std::endl;
        print();
        
    }
}



int main(int argc, const char * argv []) {
    
    std::scanf("%d", &N);
    init();
    solve(N);
    
    for (int i = 0; i <= N; ++i) {
        R += DP[i];
    }
    std::printf("%d", R % 9901);
    
    return 0;
}
