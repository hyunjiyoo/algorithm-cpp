#include <string>
#include <vector>
#include <iostream>

using namespace std;

int cnt = 0;

int sum(vector<int>& numbers) {
    int tot = 0;
    for (int i = 0; i < numbers.size(); ++i)
        tot += numbers[i];
    
    return tot;
}


void calc(vector<int>& numbers, int& target, int step = 0) {
    
    if (step == numbers.size()) {
        cnt += (sum(numbers) == target);
        return;
    }
    
    for (int i = 0; i < 2; ++i) {
        numbers[step] = -numbers[step];
        calc(numbers, target, step + 1);
    }
}

int solution(vector<int> numbers, int target) {
    
    calc(numbers, target);
    
    return cnt;
}

int main() {
    vector<int> numbers = {1, 1, 1, 1, 1};
    cout << solution(numbers, 3) << endl;
    
    return 0;
}
