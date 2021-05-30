#include <iostream>
#include <string>

int CASE, n;
std::string cloth[31];
int count[31];
int R;

void init() {
    n = 0;
    R = 1;
    for (int i = 0; i <= 30; ++i) {
        cloth[i] = " ";
        count[i] = 0;
    }
}

void input() {
    std::cin >> n;
    std::string c, type;
    for (int i = 0; i < n; ++i) {
        std::cin >> c >> type;
        cloth[i] = type;
    }
}

void solve() {
    
    for (int i = 0; i < n; ++i) {
        if (cloth[i] != " ") {
            count[i] = 1;
            for (int j = i + 1; j < n; ++j) {
                if (cloth[i] == cloth[j]) {
                    cloth[j] = " ";
                    ++count[i];
                }
            }
        }
    }
    
    for (int i = 0; i < n; ++i) {
        if (count[i] == 0) continue;
        R *= (count[i] + 1);
    }
    
    R -= 1;
}

int main (int argc, const char * argv []) {
    std::cin >> CASE;
    
    for (int i = 0; i < CASE; ++i) {
        init();
        input();
        solve();
        std::cout << R << std::endl;
    }
    
    return 0;
}
