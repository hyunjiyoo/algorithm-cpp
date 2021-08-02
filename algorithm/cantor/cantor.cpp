#include <iostream>
#include <string>
#include <cmath>

int N;
std::string s;

void solve(int start, int n) {
    
    if (n == 1) return;
    
    for (int i = start + (n / 3); i < start + ((2 * n) / 3); ++i) {
        s[i] = ' ';
    }
    
    solve(start, n / 3);
    solve(start + (n * 2 / 3), n / 3);
}

int main (int argc, const char * argv []) {
    
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    while (true) {
        s.clear();
        std::cin >> N;
        
        if (std::cin.eof()) break;
        
        for (int i = 0; i < pow(3, N); ++i)
            s += '-';
        
        solve(0, pow(3, N));
        std::cout << s << std::endl;
    }
    
    return 0;
}
