#include <iostream>

int n;
int64_t DP[101] = {0, 1, 2, 3, 4, 5 };

int main (int argc, const char * argv []) {
    
    std::ios::sync_with_stdio(false);
    
    std::cin >> n;
   
    for (int i = 1; i <= n; ++i) {
        DP[i] = i;
        
        for (int j = 1; j < i; ++j) {
            int64_t count = DP[j] * (i - j - 1);
            
            if (DP[i] < count)
                DP[i] = count;
        }
    }
    
    std::cout << DP[n];
    
    return 0;
}
