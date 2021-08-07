#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int seq = 1;
    queue<pair<int, int>> truck;
    vector<pair<int, int>> pass_truck;
    
    for (int i = 0; i < truck_weights.size(); ++i)
        truck.push({ truck_weights[i], 1 });

    
    int w = truck.front().first;
    pass_truck.push(truck.front());
    truck.pop();
    
    while (!pass_truck.empty()) {
        
        if (pass_truck.front().second < bridge_length) {
            
            ++pass_truck.front().second;
        }
        else {
            w -= pass_truck.front().first;
            pass_truck.pop();
        }
        
        if (!truck.empty() && w + truck.front().first <= weight) {
            pass_truck.push(truck.front());
            w += truck.front().first;
            truck.pop();
        }
        
        ++seq;
    }
    
    return seq;
}

int main() {
    
    cout << solution(3, 15, {7,4,5,6}) << endl;
    cout << solution(2, 10, {7,4,5,6}) << endl;
    cout << solution(100, 100, {10}) << endl;
    cout << solution(100, 100, {10,10,10,10,10,10,10,10,10,10}) << endl;
    
    return 0;
}
