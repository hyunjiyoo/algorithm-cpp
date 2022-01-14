#include <iostream>
#include <string>

std::string X;

void solve(int step = 0, std::string s = X) {
    
    if (s.size() == 1) {
        std::printf("%d\n", step);

        int num = s[0] - '0';

        if (num % 3 == 0) {
            std::cout << "YES";
        } else {
            std::cout << "NO";
        }
        
        return;
    }
    
    int sum = 0;
    for (char c : s)
        sum += (c - '0');
    
    solve(step + 1, std::to_string(sum));
}

int main (int argc, const char * argv []) {
    
    std::cin >> X;
    solve();
    
    return 0;
}
