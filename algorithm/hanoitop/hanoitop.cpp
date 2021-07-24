#include <iostream>

int N;
int count[21] = { 0, 1, 3, 7, };

void getTotCount() {
    for (int i = 3; i <= N; ++i)
        count[i] = count[i - 1] * 2 + 1;
    
    std::cout << count[N] << '\n';
}

void solve(int n, int a, int b) {
    
    if (n == 1) {
        std::cout << a << ' ' << b << '\n';
        return;
    }
        
    solve(n - 1, a, 6 - a - b);
    solve(1, a, b);
    solve(n - 1, 6 - a - b, b);
}

int main(int argc, const char * argv[]) {

    std::ios::sync_with_stdio(false);
    std::cin >> N;
    getTotCount();
    solve(N, 1, 3);
    
    return 0;
}
