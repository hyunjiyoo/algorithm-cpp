#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    vector<bool> num(202, false);
    
    for (int i = 0; i < numbers.size(); ++i) {
        for (int j = 0; j < numbers.size(); ++j) {
            if (i == j) continue;
            num[numbers[i] + numbers[j]] = true;
        }
    }
    
    for (int i = 0; i < 202; ++i) {
        if (num[i])
            answer.push_back(i);
    }
    
    return answer;
}
