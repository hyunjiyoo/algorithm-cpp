#include <iostream>
#include <string>
#include <cmath>

int N;

void getTotCount() {
    
    int idx;
    std::string ans;
    
    ans = std::to_string(std::pow(2, N));
    idx = ans.find('.');
    ans = ans.substr(0, idx);
    ans[ans.length() - 1] -= 1;
    
    std::cout << ans;
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
    
    if (N <= 20) {
        std::cout << '\n';
        solve(N, 1, 3);
    }
    
    return 0;
}
