#include <iostream>

int N;
int dp[100][10] =
{ {0,1,1,1,1,1,1,1,1,1}, };

int main (int argc, const char * argv []) {
    
    std::ios::sync_with_stdio(false);
    std::cin >> N;
    
    for (int i = 1; i < 100; ++i) {
        dp[i][0] = dp[i - 1][1];
        
        for (int j = 1; j < 9; ++j)
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1'000'000'000;
        
        dp[i][9] = dp[i - 1][8];
    }
    
    int sum = 0;
    for (int i = 0; i < 10; ++i)
        sum = (sum + dp[N - 1][i]) % 1'000'000'000;
    
    std::cout << sum;
    
    return 0;
}
