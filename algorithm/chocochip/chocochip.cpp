#include <iostream>

int n, q;
int line[30'000][3];
int horizontal_max, vertical_max;
int horizontal_max_cnt, vertical_max_cnt;

enum {
    horizontal = 1,
    vertical = 2,
};

void input() {
    std::scanf("%d %d", &n, &q);
}

void init() {
    horizontal_max_cnt = vertical_max_cnt = horizontal_max = vertical_max = 0;
    
    for (int i = 0; i < n; ++i)
        line[i][1] = line[i][2] = 0;
}

void solve() {
    
    bool horizontal_flag = false;
    bool vertical_flag = false;
    
    int direction = 0;
    int line_num = 0;
    int count = 0;
    
    for (int i = 0; i < q; ++i) {
        std::scanf("%d %d", &direction, &line_num);
        
        if (direction == horizontal) {
            horizontal_flag = true;
            ++line[line_num - 1][horizontal];
            
            if (horizontal_max < line[line_num - 1][horizontal]) {
                horizontal_max = line[line_num - 1][horizontal];
                horizontal_max_cnt = 0;
            }
                
            if (horizontal_max == line[line_num - 1][horizontal])
                ++horizontal_max_cnt;
        }
        
        if (direction == vertical) {
            vertical_flag = true;
            ++line[line_num - 1][vertical];
            
            if (vertical_max < line[line_num - 1][vertical]) {
                vertical_max = line[line_num - 1][vertical];
                vertical_max_cnt = 0;
            }
            
            if (vertical_max == line[line_num - 1][vertical])
                ++vertical_max_cnt;
        }
        
        if (horizontal_flag && vertical_flag) {
            count = horizontal_max_cnt * vertical_max_cnt;
        }
        else {
            if (!horizontal_flag) {
                count = vertical_max_cnt * n;
            }
            else if (!vertical_flag) {
                count = horizontal_max_cnt * n;
            }
        }
        
        std::printf("%d\n", count);
    }
}

int main (int argc, const char * argv []) {
    
    input();
    init();
    solve();
    
    return 0;
}
