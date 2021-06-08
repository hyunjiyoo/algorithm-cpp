#include <iostream>
#include <cmath>
#include <vector>

int G;
int64_t _pow[50'001];
std::vector<int> weight;

void solve() {
    int left = 1;
    int right = 2;
    int64_t diff;
    
    while (left < 50'001) {
        diff = _pow[right] - _pow[left];
        
        if (diff < G) {
            while (right < 50'001 && diff < G)
                diff = _pow[++right] - _pow[left];
        }
        else {
            while (left < right && diff > G)
                diff = _pow[--right] - _pow[left];
        }
        
        if (diff == G)
            weight.push_back(right);
        
        ++left;
    }
}

void output() {
    if (weight.empty())
        std::printf("-1");
    else
        for (int i = 0; i < weight.size(); ++i)
            std::printf("%d\n", weight[i]);
}

int main (int argc, const char * argv []) {
    
    std::scanf("%d", &G);
    for (int i = 0; i < 50'001; ++i)
        _pow[i] = std::pow(i, 2);
    
    solve();
    output();
    
    return 0;
}
