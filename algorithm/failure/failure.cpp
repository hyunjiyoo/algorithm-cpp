#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    vector<float> top(N + 2, 0.0);
    vector<float> bottom(N + 2, 0.0);
    for (int i = 0; i < stages.size(); ++i) {
        ++top[stages[i]];
        for (int j = 1; j <= stages[i]; ++j)
            ++bottom[j];
    }
    
    vector<pair<float, int>> failure;
    for (int i = 1; i <= N; ++i) {
        if (bottom[i] != 0)
            failure.push_back(make_pair(top[i]/bottom[i], i));
        else
            failure.push_back(make_pair(0.0, i));
            
    }
    
    sort(failure.begin(), failure.end(), [&](const pair<float, int>& a, const pair<float, int>& b) {
        if (a.first == b.first)
            return a.second < b.second;
            
        return a.first > b.first;
    });
    
    
    for (int i = 0; i < N; ++i)
        answer.push_back(failure[i].second);
    
    return answer;
}
