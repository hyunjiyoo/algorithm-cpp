#include <iostream>

int n;
int five_cnt;
int two_cnt;

void pickOptimalFive() {
    int isFiveOdd = (n % 5) % 2;
    
    five_cnt = n / 5;
    
    if (isFiveOdd && five_cnt > 0)
        five_cnt -= 1;
}

int solve() {
    pickOptimalFive();
    
    two_cnt = (n - (5 * five_cnt)) / 2;
    
    int isTwoOdd = (n - (5 * five_cnt)) % 2;
    if (isTwoOdd)
        return -1;
    
    return five_cnt + two_cnt;
}

int main(int argc, const char * argv[]) {
    
    std::cin >> n;
    std::cout << solve();
    
    return 0;
}
