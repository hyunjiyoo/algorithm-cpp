#include <vector>
#include <queue>

using namespace std;


int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 1;
    
    vector<int> v;
    queue<int> q;

    v.resize(truck_weights.size());
    fill_n(v.begin(), v.size(), 0);
    q.push(truck_weights[0]);
    
    v[0] = 1;
    
    int w = q.front();
    int next = 1;
    int prev = 0;
    
    while (!q.empty()) {
        if (v[prev] == bridge_length) {
            ++prev;
            w -= q.front();
            q.pop();
        }
        
        if (w + truck_weights[next] <= weight && next < truck_weights.size()) {
            w += truck_weights[next];
            q.push(truck_weights[next++]);
        }
        
        for (int i = prev; i < next; ++i)
            ++v[i];
        
        ++answer;
    }
    
    return answer;
}


int main() {
    
    cout << solution(3, 11, {7,4,5,6}) << endl; // 8
    cout << solution(2, 10, {7,4,5,6}) << endl; // 8
    cout << solution(100, 100, {10}) << endl; // 101
    cout << solution(100, 100, {10,10,10,10,10,10,10,10,10,10}) << endl; // 110
    
    return 0;
}
