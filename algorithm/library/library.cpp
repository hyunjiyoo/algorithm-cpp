#include <iostream>
#include <algorithm>
#include <vector>

using vec = std::vector<int>;

int N, M, R;
vec b1, b2;

void input() {
    std::scanf("%d %d", &N, &M);
    
    int book = 0;
    for (int i = 0; i < N; ++i) {
        std::scanf("%d", &book);
        if (book > 0)
            b1.push_back(book);
        else
            b2.push_back(-book);
    }
    std::sort(b1.rbegin(), b1.rend());
    std::sort(b2.rbegin(), b2.rend());
    
    if (b1.empty()) b1.push_back(0);
    if (b2.empty()) b2.push_back(0);
}

void solve(vec& b1, vec& b2) {
    R = -b1[0];
    for (int i = 0; i < b1.size(); i += M)
        R += (b1[i] * 2);
    for (int i = 0; i < b2.size(); i += M)
        R += (b2[i] * 2);
}


int main (int argc, const char * argv []) {
    input();
    if (b1[0] > b2[0])
        solve(b1, b2);
    else
        solve(b2, b1);
    
    std::printf("%d", R);
    
    return 0;
}
