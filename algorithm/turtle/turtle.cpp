#include <iostream>
#include <string>
#include <algorithm>

int T;
int minX, minY, maxX, maxY;
std::string order;

const int offset[4][2] = {
    {1, 0}, {0, -1}, {-1, 0}, {0, 1},
};

void init() {
    minX = minY = maxX = maxY = 0;
}

void solve(int y = 0, int x = 0, int step = 0, int d = 0) {
    
    if (step == order.length())
        return;
    
    if (order[step] == 'F') {
        y += offset[d][0];
        x += offset[d][1];
    }
    else if (order[step] == 'B') {
        y += (offset[d][0] * -1);
        x += (offset[d][1] * -1);
    }
    else if (order[step] == 'L') {
        direction = (d + 1) % 4;
    }
    else if (order[step] == 'R') {
        direction = (d + 3) % 4;
    }
    
    minX = std::min(minX, x);
    minY = std::min(minY, y);
    maxX = std::max(maxX, x);
    maxY = std::max(maxY, y);
    
    solve(y, x, step + 1, d);
}

int main (int argc, const char * argv []) {
    
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> T;
    
    for (int i = 0; i < T; ++i) {
        std::cin >> order;
        
        init();
        solve();
        
        std::cout << (maxY - minY) * (maxX - minX) << '\n';
    }
    
    return 0;
}
