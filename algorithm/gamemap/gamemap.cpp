#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> maps) {
    int count = -1;
    bool flag = false;
    queue<pair<int, int>> q;
    vector<vector<bool>> reachable;
    int offset[4][2] = {{ 0, 1 }, { 1, 0 }, { -1, 0 }, { 0, -1 }};
    
    reachable.resize(maps.size());
    for (int i = 0; i < reachable.size(); ++i)
        reachable[i].resize(maps[0].size());
    
    
    int y, x;
    y = x = 0;
    q.push(pair<int, int>(y, x));
    
    while (!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        
        if (y == maps.size() - 1 && x == maps[0].size() - 1) {
            flag = true;
            break;
        }
        
        for (int i = 0; i < 4; ++i) {
            int ny = y + offset[i][0];
            int nx = x + offset[i][1];
            
            if (!(0 <= ny && ny < maps.size() && 0 <= nx && nx < maps[0].size()))
                continue;
           
            if (!reachable[ny][nx] && maps[ny][nx]) {
                reachable[y][x] = true;
                q.push(pair<int, int>(ny, nx));
                maps[ny][nx] = maps[y][x] + 1;
            }
        }
        
        q.pop();
    }
    
    if (flag)
        count = maps[y][x];
    
    return count;
}


int main() {
    vector<vector<int>> maps = {{1,0,1,1,1},
                                {1,0,1,0,1},
                                {1,0,1,1,1},
                                {1,1,1,0,1},
                                {0,0,0,0,1}};
    
    cout << solution(maps) << endl;
    
    return 0;
}
