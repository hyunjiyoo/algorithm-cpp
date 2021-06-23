#include <vector>
#include <limits>
#include <iostream>

using namespace std;

vector<vector<bool>> reachable;
int min_count = numeric_limits<int>::max();
int offset[4][2] = {{ 0, 1 }, { 1, 0 }, { -1, 0 }, { 0, -1 }};
bool flag = false;

void play(vector<vector<int>>& maps, int y, int x, int count) {
    
    if (count > min_count) return;
    
    if (y == (int)maps.size() - 1 && x == (int)maps[0].size() - 1) {
        min_count = (min_count < count) ? min_count : count;
        flag = true;
        return;
    }
    
    for (int i = 0; i < 4; ++i) {
        int ny = y + offset[i][0];
        int nx = x + offset[i][1];
        
        if (!(0 <= ny && ny < (int)maps.size() && 0 <= nx && nx < (int)maps[0].size()))
            continue;
        
        if (reachable[ny][nx]) continue;
        
        if (maps[ny][nx]) {
            reachable[ny][nx] = true;
        
            play(maps, ny, nx, count + 1);
            reachable[ny][nx] = false;
        }
        
    }
    
}

int solution(vector<vector<int>> maps) {
        
    reachable.resize(maps.size());
    for (int i = 0; i < reachable.size(); ++i)
        reachable[i].resize(maps[i].size());
    
    
    play(maps,0, 0, 1);
    
    if (!flag)
        min_count = -1;

    return min_count;
}


int main() {
    
    vector<vector<int>> maps = {{1,0,1,1,1},
                                {1,0,1,0,1},
                                {1,0,1,1,1},
                                {1,1,1,0,0},
                                {0,0,0,0,1}};
    
    
    cout << solution(maps) << endl;
    
    return 0;
}
