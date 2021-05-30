#include <iostream>
#include <algorithm>

int height[9];
int sum = 0;
int result[7];

bool solve(int idx = 0, int before = -1, int accum = 0) {
    if (idx == 7) {
        if (accum == 100) {
            return true;
        }
        return false;
    }
    
    for (int i = before + 1; i < 9; ++i) {
        result[idx] = height[i];
        if (solve(idx + 1, i, accum + height[i]))
            return true;
    }
    return false;
}

int main(int argc, const char* argv[]) {
    for (int i = 0; i < 9; ++i)
        std::scanf("%d", height + i);
    
    solve();
    
    std::sort(result, result + 7);
    
    for (int i = 0; i < 7; ++i)
        std::printf("%d\n", result[i]);
    
    return 0;
}
