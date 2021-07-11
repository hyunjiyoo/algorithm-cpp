#include <iostream>

int n;

void solve() {
    
    int two_cnt = 0;
    int five_cnt = n / 5;
    
    int change = n - (5 * five_cnt);
    
    if (change % 2 == 0) {
        two_cnt = change / 2;
    }
    else {
        if (five_cnt != 0) {
            --five_cnt;
            two_cnt = change / 2 + 3;
        }
    }
    
    if (five_cnt * 5 + two_cnt * 2 == n)
        std::printf("%d", five_cnt + two_cnt);
    else
        std::printf("-1");
}

int main (int argc, const char * argv []) {
    
    std::scanf("%d", &n);
    solve();
    
    return 0;
}
