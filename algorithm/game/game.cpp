#include <iostream>

long long X, Y;

void input() {
    std::ios::sync_with_stdio(false);
    std::cin >> X >> Y;
}

bool changeScore(long long n) {
    long long SCORE = (Y * 100) / X;
    long long new_score = ((Y + n) * 100) / (X + n);

    return (new_score != SCORE);
}

void solve() {
    
    long long left = 1;
    long long right = 1'000'000'000;
    long long mid = (left + right) / 2;
    bool flag = false;
    
    while (left <= right) {
        
        if (changeScore(mid)) {
            right = mid - 1;
            flag = true;
        }
        else {
            left = mid + 1;
        }
        
        mid = (left + right) / 2;
    }
    
    if (flag)
        std::cout << left;
    else
        std::cout << "-1";
}

int main (int argc, const char * argv []) {
    
    input();
    solve();
    
    return 0;
}
