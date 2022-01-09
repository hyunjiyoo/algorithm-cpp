#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;



//vector<vector<int>> costs = {{0,1,1},{0,2,2},{1,2,5},{1,3,1},{2,3,8}};
vector<vector<int>> costs = {{0,1,1},{1,2,5},{2,3,1}};


int solution(int n) {
    
    int answer = 0;
    vector<int> cycle;
    vector<bool> visited;
    vector<vector<int>> map;
    queue<pair<int, int>> q;

    visited.resize(n);
    cycle.resize(n);
    for (int i = 0; i < n; ++i)
        cycle[i] = i;
    
    map.resize(n);
    for (int i = 0; i < n; ++i)
        map[i].resize(n);
    
    for (int i = 0; i < costs.size(); ++i) {
        map[costs[i][0]][costs[i][1]] = costs[i][2];
        map[costs[i][1]][costs[i][0]] = costs[i][2];
    }
    

    sort(costs.begin(), costs.end(), [&](auto a, auto b) {
        return a[2] < b[2];
    });
    
    
    for (int i = 0; i < costs.size(); ++i) {
        q.push({costs[i][0], costs[i][1]});
    }
    
    visited[q.front().first] = true;
    while (!q.empty()) {
        
        int curr = q.front().first;
        int next = q.front().second;
        
        if (cycle[curr] != cycle[next]) {
            visited[next] = true;
            cycle[next] = cycle[curr];
            answer += map[curr][next];
        }
        
        q.pop();
    }
    
    return answer;
}




int main (int argc, const char* argv []) {

    cout << solution(4) << endl;

    return 0;
}
